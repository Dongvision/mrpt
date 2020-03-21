/* +------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)            |
   |                          https://www.mrpt.org/                         |
   |                                                                        |
   | Copyright (c) 2005-2020, Individual contributors, see AUTHORS file     |
   | See: https://www.mrpt.org/Authors - All rights reserved.               |
   | Released under BSD License. See: https://www.mrpt.org/License          |
   +------------------------------------------------------------------------+ */

#include "_DSceneViewerApp.h"

//(*AppHeaders
#include <wx/image.h>
#include "_DSceneViewerMain.h"
//*)
#include <wx/stdpaths.h>

IMPLEMENT_APP(_DSceneViewerApp)

// The file to open (from cmd line), or an empty string
std::string global_fileToOpen;

#include <mrpt/config/CConfigFile.h>
#include <mrpt/gui/WxUtils.h>
#include <mrpt/system/filesystem.h>
using namespace mrpt;
using namespace mrpt::config;

// The configuration file:
std::unique_ptr<CConfigFile> iniFile;

bool _DSceneViewerApp::OnInit()
{
	// Starting in wxWidgets 2.9.0, we must reset numerics locale to "C",
	//  if we want numbers to use "." in all countries. The App::OnInit() is a
	//  perfect place to undo
	//  the default wxWidgets settings. (JL @ Sep-2009)
	wxSetlocale(LC_NUMERIC, wxString(wxT("C")));

	// Process cmd line arguments (for the case of opening a file):
	if (argc > 1) global_fileToOpen = wxString(wxApp::argv[1]).mb_str();

	// Create the INI file:
	// wxStandardPaths stdPaths;
	// wxString    dataDir = stdPaths.GetUserDataDir();
	wxString dataDir = wxStandardPaths::Get().GetUserDataDir();
	std::string dataDirStr(dataDir.mb_str());
	mrpt::system::createDirectory(dataDirStr);  // Create dir!
	std::string iniFileName(dataDirStr + std::string("/config.cfg"));
	iniFile = std::make_unique<CConfigFile>(iniFileName);

	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if (wxsOK)
	{
		auto* Frame = new _DSceneViewerFrame(nullptr);
		Frame->Show();
		SetTopWindow(Frame);
	}
	//*)
	return wxsOK;
}

int _DSceneViewerApp::OnExit() { return 0; }
