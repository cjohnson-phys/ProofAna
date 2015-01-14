for number in range(4):
  outfile = open("test_Indiana_xrootdJZ{0}W.forwardnew.txt".format(number),'w')
  with open("test_Indiana_xrootd.forwardnew.txt",'r') as infile:
    for line in infile:
      if "JZ{0}W".format(number) in line:
        outfile.write(line)
  outfile.close()
