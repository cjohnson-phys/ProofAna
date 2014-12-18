#include <fstream>
#include <TSystem.h>

void load_packages ()
{
  std::string cxxflags;

  const char *env_CXXFLAGS = gSystem->Getenv ("CXXFLAGS");
  if (env_CXXFLAGS != 0)
  {
    cxxflags += " ";
    cxxflags += env_CXXFLAGS;
  }
  const char *env_EXTRA_CFLAGS = gSystem->Getenv ("EXTRA_CFLAGS");
  if (env_EXTRA_CFLAGS != 0)
  {
    cxxflags += " ";
    cxxflags += env_EXTRA_CFLAGS;
  }
  const char *env_CPPEXPFLAGS = gSystem->Getenv ("CPPEXPFLAGS");
  if (env_CPPEXPFLAGS != 0)
  {
    cxxflags += " ";
    cxxflags += env_CPPEXPFLAGS;
  }
  if (!cxxflags.empty())
  {
    std::string optflags   = gSystem->GetFlagsOpt();
    std::string debugflags = gSystem->GetFlagsDebug();
    gSystem->SetFlagsOpt   ((optflags   + cxxflags).c_str());
    gSystem->SetFlagsDebug ((debugflags + cxxflags).c_str());
  }

  const char *root_core_dir = gSystem->Getenv ("ROOTCOREBIN");
  if (root_core_dir == 0)
    throw std::string ("ROOTCOREBIN not set, try sourcing RootCoreDir/setup.sh");
  const std::string dir = root_core_dir;

  const std::string include_dir = dir + "/include";
  if (gSystem->AccessPathName (include_dir.c_str()) == 1)
  {
    throw std::string ("failed to find " + include_dir);
  }
  gSystem->AddIncludePath (("-I\"" + include_dir + "\"").c_str());

  const std::string lib_dir = dir + "/lib";
  if (gSystem->AccessPathName (lib_dir.c_str()) == 1)
  {
    throw std::string ("failed to find " + lib_dir);
  }

  std::ifstream preload_file ((dir + "/preload").c_str());
  std::string preload;
  while (std::getline (preload_file, preload))
  {
    if (!preload.empty() && preload[0] != '#')
    {
      if (gSystem->Load (preload.c_str()) < 0)
      {
	throw std::string ("failed to load library " + preload);
      }
    }
  }

  std::ifstream pkg_file ((dir + "/load").c_str());
  std::string name;
  while (std::getline (pkg_file, name))
  {
    if (!name.empty())
    {
      const std::string glob_lib = lib_dir + "/lib" + name + ".so";
      if (gSystem->Load (glob_lib.c_str()) < 0)
      {
	throw std::string ("failed to load library " + glob_lib);
      }
    }
  }

  if (gSystem->AccessPathName ((dir + "/load_packages_success").c_str()) != 0)
    std::ofstream success ((dir + "/load_packages_success").c_str());
}
