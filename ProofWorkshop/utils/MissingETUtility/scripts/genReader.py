import sys, os

# First make sure ROOT is initialised
try:
    import ROOT
    from ROOT import TTree, TSelector, TFile
except:
    print 'Could not set up ROOT!'
    sys.exit(1)

if len(sys.argv) < 3:
    print 'syntax for calling genReader.py is `genReader.py [inputfile] [treename] [varlist]`'
    sys.exit(1)

inputfile = sys.argv[1]
treename = sys.argv[2]
varlist = sys.argv[3]

print 'Generating TSelector source files EventReader.h and EventReader.C'
print 'from tree {0} in file {1}'.format(treename, inputfile)

print 'WARNING: MET terms are assumed to be written using etx,ety.'
print '         Some modification is necessary if your D3PD only has et,phi.'

rootfile = TFile(inputfile)
ntuple = rootfile.Get(treename)
if ntuple == None:
    print 'TTree {0} not found in root file {1}! Aborting.'.format(treename, inputfile)
    sys.exit(1)

varfile = open(varlist)
branches = []
print 'Branches to be retained:'
for branch in varfile.read().splitlines():
    if branch.startswith('#'): continue
    if '#' in branch: branch = branch.split('#',1)[0]
    branch = branch.rstrip()
    branches.append(branch)
    print branch

ntuple.MakeSelector('EventReader_temp')

# Here we prune the .h file to kill off all the branches we don't care about
# Also set up aliases for a handful of variables

# Specific classes that might be in a TTree
basictypes = [
    'Bool_t',
    'Int_t',
    'UInt_t',
    'Char_t',
    'Float_t'
    ]

htemp = open('EventReader_temp.h')
hfile = open('../macros/EventReader.h','w')

wroteIncludeVector = False
aliases = []
for line in htemp.read().splitlines():
    line = line.replace('_temp','')
    pieces = line.split()

    # Empty lines
    if len(pieces) == 0:
        hfile.write('\n')
        continue

    # Filter the code for commands that are specific to branches
    # and throw away all branches that aren't needed
    if pieces[0] in basictypes or pieces[0] == 'TBranch':
        if 'EventReader::' in pieces[1]:
            # This is a function declaration
            hfile.write(line+'\n')
            continue
        # This is a declaration
        bname = pieces[1].lstrip('*b_').rstrip(';')
        if bname in branches:
            hfile.write(line+'\n')
            # Set up aliases
            if not 'TBranch' in pieces[0]:
                if 'jet_' in bname:
                    (jetpref,jettype,jetvar) = bname.split('_',2)
                    aliases.append(('jet_{0}'.format(jetvar),bname,pieces[0]))
                if 'mu_' in bname:
                    (mupref,mutype,muvar) = bname.split('_',2)
                    aliases.append(('mu_{0}'.format(muvar),bname,pieces[0]))
    elif pieces[0].startswith('vector<'):
        # Need to allow for spaces in vector template declarations
        depth = line.count('vector')
        isunsigned = line.count('unsigned')
        # Determine the vector type
        type = ''
        for i in range(0,depth+isunsigned):
            type += pieces[i]
        while type.count('>>') > 0:
            type = type.replace('>>','> >')
        type = type.replace('unsigned','unsigned ')
        # Get the branch name
        bname = pieces[depth+isunsigned].lstrip('*').rstrip(';')
        if bname in branches:
            hfile.write(line+'\n')
            # Set up aliases
            if 'jet_' in bname:
                (jetpref,jettype,jetvar) = bname.split('_',2)
                if 'JES' in jetvar:
                    jetvar = 'JES'
                aliases.append(('jet_{0}'.format(jetvar),bname,type))
            if 'mu_' in bname:
                (mupref,mutype,muvar) = bname.split('_',2)
                aliases.append(('mu_{0}'.format(muvar),bname,type))
    elif line.endswith('= 0;'):
        # This is an initialisation of a pointer
        if pieces[0] in branches:
            hfile.write(line+'\n')
    elif pieces[0].startswith('fChain->SetBranchAddress'):
        # This is setup of the branch reading
        bits = pieces[0].split('"')
        if bits[1] in branches:
            hfile.write(line+'\n')
            branches.remove(bits[1])
    elif 'List of branches' in line:
        # Declare some aliases for things like jets and muons with multiple types
        hfile.write('  // Generic aliases for objects with multiple types\n')
        for (alias,original,type) in aliases:
            # Assume vectors have been written as pointers
            ptr = '*' if 'vector' in type else ''
            print 'Alias: {0} {1} ==> {2}'.format(type+ptr,original,alias)
            hfile.write('  {0} {1};\n'.format(type,ptr+alias))
        hfile.write('\n')
        hfile.write(line+'\n')
    else:
        # Anything else, we just write -- it is generic
        if line == '#include <vector>':
            if not wroteIncludeVector:
                hfile.write(line+'\n')
                hfile.write('using std::vector;\n')
                wroteIncludeVector = True
        else:
            hfile.write(line+'\n')

if len(branches)>0:
    print 'The following variables were not found:'
    for bname in branches:
        print bname
htemp.close()
hfile.close()
os.unlink('EventReader_temp.h')

# Now hack the .C file a bit to make sure the aliases are properly handled

ctemp = open('EventReader_temp.C')
cfile = open('../macros/EventReader.C','w')

for line in ctemp.read().splitlines():
    line = line.replace('_temp','')
    
    # In the Process() method, set aliases to the values of their targets
    if 'return kTRUE' in line:
        # This is the last line of Process(), and doesn't show up in the other methods
        cfile.write('  GetEntry(entry);\n\n')
        for (alias,original,type) in aliases:
            cfile.write('   {0} = {1};\n'.format(alias,original))
        cfile.write('\n')
        cfile.write('\n')
    cfile.write(line+'\n')

ctemp.close()
cfile.close()
os.unlink('EventReader_temp.C')
