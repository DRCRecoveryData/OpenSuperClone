// Copyright (C) Scott Dwyer and OpenSuperClone contributors.
// You may use/distribute/modify this freely, under the terms of
// the GNU General Public License version 2 or later version.
// This software is distributed WITHOUT ANY WARRANTY.

#include <string.h>

#include "clone_gui_language.h"

int setup_enlanguage_ccc(void)
{
  strcpy(enlang_ccc[LANGFILE], "File");
  strcpy(enlang_ccc[LANGQUIT], "Quit");
  strcpy(enlang_ccc[LANGOPENPROJ], "Open Project");
  strcpy(enlang_ccc[LANGNEWPROJ], "New Project");
  strcpy(enlang_ccc[LANGLOADPROJFILE], "Load project (progress) file");
  strcpy(enlang_ccc[LANGNEWPROJFILE], "New project (progress) file");
  strcpy(enlang_ccc[LANGERROR], "Error!");
  strcpy(enlang_ccc[LANGWARN], "Warning");
  strcpy(enlang_ccc[LANGLOGLOADERR], "Error processing log file!\nThe log file was not loaded.\n");
  strcpy(enlang_ccc[LANGLOGCHECKERR], "The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n");
  strcpy(enlang_ccc[LANGLANGUAGE], "Language");
  strcpy(enlang_ccc[LANGEXPORTLANG], "Export language");
  strcpy(enlang_ccc[LANGIMPORTLANG], "Import language");
  strcpy(enlang_ccc[LANGLANGEXPORTERR], "Cannot open file for writing");
  strcpy(enlang_ccc[LANGLANGIMPORTERR], "Cannot open file for reading");
  strcpy(enlang_ccc[LANGLANGIMPORTERR2], "Error processing imported language file");
  strcpy(enlang_ccc[LANGLANGCHANGESUCCESS], "Language successfully changed!");
  strcpy(enlang_ccc[LANGSUCCESS], "Success!");
  strcpy(enlang_ccc[LANGOPTIONS], "Options");
  strcpy(enlang_ccc[LANGSOURCE], "Choose Source Drive");
  strcpy(enlang_ccc[LANGDESTINATION], "Choose Destination");
  strcpy(enlang_ccc[LANGSOURCEERROR], "Error selecting source");
  strcpy(enlang_ccc[LANGDESTINATIONERROR], "Error selecting destination");
  strcpy(enlang_ccc[LANGDESTINATIONIMAGE], "Choose Destination Image");
  strcpy(enlang_ccc[LANGDRIVEVISABLEOS], "WARNING: This drive is also available to the OS!\nThat is too dangerous, and would likely result in a computer crash!\nPlease make sure to follow the instructions on how to hide the drive!\n");
  strcpy(enlang_ccc[LANGDRIVEISSLAVE], "WARNING: The selected device is a slave on the controller!\nThis does not always work as expected!\nThat could be very dangerous, and could result in data loss (or worse)!\nIt is recommended for the device to be master on the controller!\n");
  strcpy(enlang_ccc[LANGDRIVESAMECONTROLLER], "WARNING: There is possibly another drive on the same controller!\nYou should NEVER work with a drive when another drive is on the same controller!\nThat could be very dangerous, and could result in data loss (or worse)!\n");
  strcpy(enlang_ccc[LANGNOPROJECT], "You must choose a project first.");
  strcpy(enlang_ccc[LANGDRIVE], "Drive");
  strcpy(enlang_ccc[LANGIMAGEFILE], "Image file");
  strcpy(enlang_ccc[LANGNODESTINATION], "NULL (No destination)");
  strcpy(enlang_ccc[LANGCHOOSEIMAGE], "Choose image file");
  strcpy(enlang_ccc[LANGCONNECT], "Connect");
  strcpy(enlang_ccc[LANGDISCONNECT], "Disconnect");
  strcpy(enlang_ccc[LANGSTART], "Start");
  strcpy(enlang_ccc[LANGSTOP], "Stop");
  strcpy(enlang_ccc[LANGSTILLCONNECTED], "You must disconnect first.");
  strcpy(enlang_ccc[LANGNOTCONNECTED], "You must connect first.");
  strcpy(enlang_ccc[LANGDONTCONNECT], "You must choose a project, source, and destination before connecting.");
  strcpy(enlang_ccc[LANGCONNECTIONERR], "Unable to connect devices");
  strcpy(enlang_ccc[LANGCONNECTED], "Devices now connected");
  strcpy(enlang_ccc[LANGDISCONNECTED], "Devices now disconnected");
  strcpy(enlang_ccc[LANGSAMEDEVICE], "Source and Destination cannot be the same device");
  strcpy(enlang_ccc[LANGMISSINGPROJECT], "No project chosen\n");
  strcpy(enlang_ccc[LANGMISSINGSOURCE], "No source chosen\n");
  strcpy(enlang_ccc[LANGMISSINGDESTINATION], "No destination chosen\n");
  strcpy(enlang_ccc[LANGDRIVES], "Drives");
  strcpy(enlang_ccc[LANGMODE], "Mode");
  strcpy(enlang_ccc[LANGMODEAUTO], "Passthrough auto detect");
  strcpy(enlang_ccc[LANGMODESCSI], "Passthrough SCSI");
  strcpy(enlang_ccc[LANGMODEATA], "Passthrough ATA");
  strcpy(enlang_ccc[LANGMODEIDE], "Direct IDE");
  strcpy(enlang_ccc[LANGMODEAHCI], "Direct AHCI");
  strcpy(enlang_ccc[LANGSETTINGS], "Settings");
  strcpy(enlang_ccc[LANGADVANCED], "Advanced settings");
  strcpy(enlang_ccc[LANGCLONE], "Clone settings");
  strcpy(enlang_ccc[LANGDIRECTPIO], "Direct mode in free version is PIO only!\n");
  strcpy(enlang_ccc[LANGDIRECTLIMITED], "Recovery is also limited to 10 percent!\n");
  strcpy(enlang_ccc[LANGPHASE1BUTTON], "Phase 1");
  strcpy(enlang_ccc[LANGPHASE2BUTTON], "Phase 2");
  strcpy(enlang_ccc[LANGPHASE3BUTTON], "Phase 3");
  strcpy(enlang_ccc[LANGPHASE4BUTTON], "Phase 4");
  strcpy(enlang_ccc[LANGDIVIDEBUTTON], "Divide");
  strcpy(enlang_ccc[LANGDIVIDE2BUTTON], "Divide 2");
  strcpy(enlang_ccc[LANGTRIMBUTTON], "Trim (overrides dividing)");
  strcpy(enlang_ccc[LANGSCRAPTBUTTON], "Scrape");
  strcpy(enlang_ccc[LANGMARKBADBUTTON], "Mark Bad Head");
  strcpy(enlang_ccc[LANGREADBADBUTTON], "Read Bad Head");
  strcpy(enlang_ccc[LANGREVERSEBUTTON], "Reverse");
  strcpy(enlang_ccc[LANGSKIPFASTBUTTON], "Skip Fast");
  strcpy(enlang_ccc[LANGPHASECONTROLLABEL], "Phase Control");
  strcpy(enlang_ccc[LANGRETRIESBUTTON], "Retries");
  strcpy(enlang_ccc[LANGCLUSTERSIZEBUTTON], "Cluster size (LBA)");
  strcpy(enlang_ccc[LANGINPUTOFFSETBUTTON], "Input Offset (LBA)");
  strcpy(enlang_ccc[LANGSIZEBUTTON], "Size (LBA)");
  strcpy(enlang_ccc[LANGBLOCKSIZEBUTTON], "Block size (LBA)");
  strcpy(enlang_ccc[LANGSKIPSIZEBUTTON], "Skip Size (LBA) phase-1-2-3");
  strcpy(enlang_ccc[LANGMAXSKIPSIZEBUTTON], "Max Skip Size (LBA) phase-1-2");
  strcpy(enlang_ccc[LANGSKIPTHRESHOLDBUTTON], "Skip Threshold (ms) phase-1-2");
  strcpy(enlang_ccc[LANGRATESKIPBUTTON], "Rate Skip (kB/s) phase-3");
  strcpy(enlang_ccc[LANGEXITONSLOW], "Exit on Slow (kB/s) phase-1-2");
  strcpy(enlang_ccc[LANGEXITONSLOWTIME], "Exit on Slow Time (sec) phase-1-2");
  strcpy(enlang_ccc[LANGLOGWRITEERR], "Error writing progress log file");
  strcpy(enlang_ccc[LANGSAVEPROJFILE], "Save Project File As");
  strcpy(enlang_ccc[LANGSAVE], "Save Project");
  strcpy(enlang_ccc[LANGSAVEAS], "Save Project As");
  strcpy(enlang_ccc[LANGTOOLS], "Tools");
  strcpy(enlang_ccc[LANGRESETSTATUS], "Reset Current Status");
  strcpy(enlang_ccc[LANGOK], "OK");
  strcpy(enlang_ccc[LANGCANCEL], "Cancel");
  strcpy(enlang_ccc[LANGRESETSTATUSMESSAGE], "This will reset the current log status to Phase1,\n and current position to 0,\n and reset all skip data");
  strcpy(enlang_ccc[LANGRESETLOG], "Reset Log");
  strcpy(enlang_ccc[LANGRESETLOGMESSAGE], "This will reset the position to 0, \nthe current status to non-tried, \nand will change all unfinished blocks \nin the log to a status of non-tried. \nThis will also reset all skipping data.");
  strcpy(enlang_ccc[LANGREPAIRLOG], "Repair Log");
  strcpy(enlang_ccc[LANGREPAIRLOGMESSAGE], "This will repair the current progress log in memory. \nIt is recommended to make a backup copy of the log before repairing.");
  strcpy(enlang_ccc[LANGFILLZERO], "Fill Zero");
  strcpy(enlang_ccc[LANGFILLMARK], "Fill Mark");
  strcpy(enlang_ccc[LANGFILLERASE], "Erase Destination");
  strcpy(enlang_ccc[LANGDOMAIN], "Load Domain File");
  strcpy(enlang_ccc[LANGCHOOSENEWPROJECT], "You must start a new project before importing a ddrescue log file");
  strcpy(enlang_ccc[LANGIMPORTDD], "Import ddrescue log (map) file");
  strcpy(enlang_ccc[LANGEXPORTDD], "Export ddrescue log (map) file");
  strcpy(enlang_ccc[LANGLOGEXPORTERR], "Error exporting ddrescue log (map) file");
  strcpy(enlang_ccc[LANGPROJECTLABEL], "Project");
  strcpy(enlang_ccc[LANGSOURCELABEL], "Source");
  strcpy(enlang_ccc[LANGDESTINATIONLABEL], "Destination (All data will be overwritten!)");
  strcpy(enlang_ccc[LANGDOMAINLABEL], "Domain");
  strcpy(enlang_ccc[LANGTOTALLBALABEL], "Total LBA");
  strcpy(enlang_ccc[LANGLBATOREADLABEL], "LBA to read");
  strcpy(enlang_ccc[LANGDOMAINSIZELABEL], "Domain size");
  strcpy(enlang_ccc[LANGRUNTIMELABEL], "Run time");
  strcpy(enlang_ccc[LANGREMAININGTIMELABEL], "Remaining time");
  strcpy(enlang_ccc[LANGCURRENTPOSISIONLABEL], "Current position");
  strcpy(enlang_ccc[LANGCURRENTSTATUSLABEL], "Current status");
  strcpy(enlang_ccc[LANGCURRENTRATELABEL], "Current rate");
  strcpy(enlang_ccc[LANGRECENTRATELABEL], "Recent rate");
  strcpy(enlang_ccc[LANGTOTALRATELABEL], "Total rate");
  strcpy(enlang_ccc[LANGSKIPSIZELABEL], "Base skip size");
  strcpy(enlang_ccc[LANGSKIPSLABEL], "Skips");
  strcpy(enlang_ccc[LANGSKIPRUNSLABEL], "Skip runs");
  strcpy(enlang_ccc[LANGSKIPRESETSLABEL], "Skip resets");
  strcpy(enlang_ccc[LANGRUNSIZELABEL], "Last run size");
  strcpy(enlang_ccc[LANGFINISHEDLABEL], "Finished");
  strcpy(enlang_ccc[LANGNONTRIEDLABEL], "Non-tried");
  strcpy(enlang_ccc[LANGNONTRIMMEDLABEL], "Non-trimmed");
  strcpy(enlang_ccc[LANGNONDIVIDEDLABEL], "Non-divided");
  strcpy(enlang_ccc[LANGNONSCRAPEDLABEL], "Non-scraped");
  strcpy(enlang_ccc[LANGBADLABEL], "Bad");
  strcpy(enlang_ccc[LANGDATAPREVIEWLABEL], "Data preview");
  strcpy(enlang_ccc[LANGLONGESTREADTIMELABEL], "Current / Recent / Longest");
  strcpy(enlang_ccc[LANGFILLEDLABEL], "Filled");
  strcpy(enlang_ccc[LANGRETRIEDLABEL], "Retried");
  strcpy(enlang_ccc[LANGRETRYPASSESLABEL], "Remaining retry passes");
  strcpy(enlang_ccc[LANGCLEARDOMAIN], "Clear Domain");
  strcpy(enlang_ccc[LANGLOGBAKWRITEERR], "Error writing backup log file");
  strcpy(enlang_ccc[LANGINFO], "Information");
  strcpy(enlang_ccc[LANGEXITDUETOSLOW], "Exiting due to slow read speed");
  strcpy(enlang_ccc[LANGPOSNOTFOUND], "Internal program error, Position not found in progress log file");
  strcpy(enlang_ccc[LANGPOSOUTOFRANGE], "Internal program error, domain check returned position out of range");
  strcpy(enlang_ccc[LANGDOMAINERROR], "Internal program error processing domain check");
  strcpy(enlang_ccc[LANGTARGETISHOSTOS], "Error: Destination is detected to be the host OS drive");
  strcpy(enlang_ccc[LANGCANTOPENDESTINATION], "Error: Unable to open destination");
  strcpy(enlang_ccc[LANGCANTSEEKDESTINATION], "Error: Unable to seek destination");
  strcpy(enlang_ccc[LANGCANTGETSIZEDESTINATION], "Error: Unable to get size of destination");
  strcpy(enlang_ccc[LANGSOURCEMOUNTEDA], "Error: Source is detected to be mounted");
  strcpy(enlang_ccc[LANGSOURCEMOUNTEDB], "It is recommended to unmount all partitions on the source.\nYou can use the --force option to use the source anyway (not recommended).");
  strcpy(enlang_ccc[LANGCANTOPENSOURCE], "Error: Unable to open source");
  strcpy(enlang_ccc[LANGIDENTIFYFAILED], "Failed to perform identify device command");
  strcpy(enlang_ccc[LANGSTATUSSLASHERROR], "\nStatus / Error");
  strcpy(enlang_ccc[LANGHOSTIOERRIDENTIFY], "Host IO error during identify");
  strcpy(enlang_ccc[LANGREADCAPFAILED], "Error: Read Capacity command failed with sense data");
  strcpy(enlang_ccc[LANGHOSTIOERRCAPACITY], "Host IO error during capacity");
  strcpy(enlang_ccc[LANGSOURCESIZEINVALID], "Error: Source size is invalid");
  strcpy(enlang_ccc[LANGREADSIZEPASTEND], "Error: Read size extends past end of device");
  strcpy(enlang_ccc[LANGDEVICEFAULT], "Error: Device fault detected on source");
  strcpy(enlang_ccc[LANGHOSTIOFAULT], "Host IO error during reading source");
  strcpy(enlang_ccc[LANGFREEREADLIMIT], "Free version direct mode read reached limit of 10 percent");
  strcpy(enlang_ccc[LANGCANTWRITEDESTINATION], "Error: Unable to write to destination");
  strcpy(enlang_ccc[LANGERRORWRITINGDESTINATION], "Error writing data to destination");
  strcpy(enlang_ccc[LANGFAILEDSIZECHECK], "Failed checking of source device size");
  strcpy(enlang_ccc[LANGUNABLETOREOPEN], "Unable to reopen source device");
  strcpy(enlang_ccc[LANGSOURCEIMPROPERIDENTIFY], "Source drive did not respond properly to identify command");
  strcpy(enlang_ccc[LANGSOURCEERRORIDENTIFY], "Source drive responded with error to identify command");
  strcpy(enlang_ccc[LANGHOSTIOERRORIDENTIFY], "Host IO error during source drive identify");
  strcpy(enlang_ccc[LANGSOURCEIMPROPERCAPACITY], "Source drive did not respond properly to read capacity command");
  strcpy(enlang_ccc[LANGHOSTIOERRORCAPACITY], "Host IO error during source capacity command");
  strcpy(enlang_ccc[LANGSOURCESIZECHANGED], "Source drive reports wrong size / size changed");
  strcpy(enlang_ccc[LANGBLOCKNOTFOUND], "Error changing chunk status, block not found");
  strcpy(enlang_ccc[LANGNOTWITHINBLOCK], "Error changing chunk status, is not within the block");
  strcpy(enlang_ccc[LANGRESCUEFINISHED], "The rescue is finished using the current settings");
  strcpy(enlang_ccc[LANGALLOCATEMEMERR], "Error allocating memory");
  strcpy(enlang_ccc[LANGBUFFERADDRESSRANGE], "Unable to get buffer physical address in 32 bit range.\nPlease try Starting the Virtual Disk Driver.\n\n Alternative is to try to choose the mode again (switch to different mode and back), or restart the program.");
  strcpy(enlang_ccc[LANGPOSIXMEMFAIL], "posix_memalign failed");
  strcpy(enlang_ccc[LANGMAXSCRATCHPADSIZE], "ERROR: Maximum scratchpad size exceeded");
  strcpy(enlang_ccc[LANGMAXSENSESIZE], "ERROR: Maximum sensebuffer size exceeded");
  strcpy(enlang_ccc[LANGNOLOGBACKUP], "Do not create backup log");
  strcpy(enlang_ccc[LANGFORCEMOUNTED], "Force access of mounted disk (not recommended)");
  strcpy(enlang_ccc[LANGENABLEOUTPUTOFFSET], "Enable changing output offset (use with caution)");
  strcpy(enlang_ccc[LANGOUTPUTOFFSET], "Output Offset (default value is -1, follow input offset)");
  strcpy(enlang_ccc[LANGREOPENADVANCED], "You must reopen the advanced setting for this change to take effect");
  strcpy(enlang_ccc[LANGACTIONONERROR], "Action to perform on major drive error:");
  strcpy(enlang_ccc[LANGSTOPONERROR], "Stop cloning with error message");
  strcpy(enlang_ccc[LANGCALLCOMMAND], "Call command:");
  strcpy(enlang_ccc[LANGDRIVEUNRESPONSIVE], "The drive is still unresponsive after the command call");
  strcpy(enlang_ccc[LANGCOMMANDFAILED], "The called command failed with exit signal / status");
  strcpy(enlang_ccc[LANGTESTCOMMAND], "Test command");
  strcpy(enlang_ccc[LANGCOMMANDCOMPLETED], "The command completed normally");
  strcpy(enlang_ccc[LANGCHSERROR], "Error calculating CHS, value out of bounds");
  strcpy(enlang_ccc[LANGWRITEBUFFERDISABLE], "Disabled (safer if there is a power loss)");
  strcpy(enlang_ccc[LANGWRITEBUFFERENABLE], "Enabled (faster)");
  strcpy(enlang_ccc[LANGWRITEBUFFERLABEL], "Operating System write buffer (must disconnect to take effect)");
  strcpy(enlang_ccc[LANGHELP], "Help");
  strcpy(enlang_ccc[LANGABOUT], "About");
  strcpy(enlang_ccc[LANGTIMERS], "Timer Settings");
  strcpy(enlang_ccc[LANGTIMERINFO], "These timer settings are only for Direct IDE and Direct AHCI modes.\nThey have no effect with the passthrough modes.\n");
  strcpy(enlang_ccc[LANGINITIALBUSYWAIT], "Initial busy wait time (ms)");
  strcpy(enlang_ccc[LANGBUSYWAIT], "Busy wait time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIME], "Soft reset time (ms)");
  strcpy(enlang_ccc[LANGHARDTIME], "Hard reset time (ms)");
  strcpy(enlang_ccc[LANGPOWERTIME], "Reset timeout (ms)");
  strcpy(enlang_ccc[LANGGENERALTIME], "General timeout (ms)");
  strcpy(enlang_ccc[LANGPOWERACTION], "Action for reset timeout");
  strcpy(enlang_ccc[LANGSTOPONPOWER], "Do nothing");
  strcpy(enlang_ccc[LANGWRONGDRIVEFORLOG1], "The end does not equal the drive size!\nLogfile reports size of ");
  strcpy(enlang_ccc[LANGWRONGDRIVEFORLOG2], ",\nbut source has a size of ");
  strcpy(enlang_ccc[LANGWRONGDRIVEFORLOG3], ".\nAre you sure this is the correct progress log file for this drive?\n");
  strcpy(enlang_ccc[LANGFORCEDANGEROUS], "Force same controller / slave (not recommended)");
  strcpy(enlang_ccc[LANGPIOMODE], "PIO mode");
  strcpy(enlang_ccc[LANGPHASETIMERS], "Phase timers (soft reset timers)");
  strcpy(enlang_ccc[LANGSOFTTIMEP12], "Phase 1-2 reset time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIMEP3], "Phase 3 reset time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIMEP4], "Phase 4 reset time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIMETD], "Trim/Divide reset time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIMED2], "Divide 2 reset time (ms)");
  strcpy(enlang_ccc[LANGSOFTTIMESC], "Scrape reset time (ms)");
  strcpy(enlang_ccc[LANGPHASETIMERSENABLE], "Enable phase timers");
  strcpy(enlang_ccc[LANGBLOCKDEV], "Generic block device");
  strcpy(enlang_ccc[LANGGENERIC], "Generic source device");
  strcpy(enlang_ccc[LANGCANTSEEKSOURCE], "Error: Unable to seek source");
  strcpy(enlang_ccc[LANGCANTREADSOURCE], "Error: Unable to read source");
  strcpy(enlang_ccc[LANGSOURCENOTDIVISABLE], "Error: Source size is not divisable by sector size,\nsource size is");
  strcpy(enlang_ccc[LANGCOPYIMAGE], "Generic source file");
  strcpy(enlang_ccc[LANGBLOCKALIGNMENT], "Alignment offset (LBA)");
  strcpy(enlang_ccc[LANGSECTORSIZE], "Sector size (bytes)");
  strcpy(enlang_ccc[LANGSOFTTIMERT], "Retry reset time (ms)");
  strcpy(enlang_ccc[LANGENABLEPROCESSCHUNK], "Enable using ATA return to mark bad sectors");
  strcpy(enlang_ccc[LANGENABLEPHASELOG], "Enable phase logs");
  strcpy(enlang_ccc[LANGCLONEMODEBUTTON], "Clone\nMode");
  strcpy(enlang_ccc[LANGDRIVERMODE], "Clone/Driver Mode");
  strcpy(enlang_ccc[LANGCLONEMODE], "Clone");
  strcpy(enlang_ccc[LANGUERROROPENINGDRIVER], "Error opening virtual disk driver");
  strcpy(enlang_ccc[LANGERRORSTOPINGDRIVER], "Error stoping virtual disk driver");
  strcpy(enlang_ccc[LANGERRORCLOSINGINGDRIVER], "Error closing virtual disk driver");
  strcpy(enlang_ccc[LANGERRORSTARTINGDRIVER], "Error starting virtual disk driver");
  strcpy(enlang_ccc[LANGERRORDRIVEROFFSET], "Error: Offset not allowed in driver mode");
  strcpy(enlang_ccc[LANGDRIVERBUFFEREXCEEDED], "Internal driver buffer error");
  strcpy(enlang_ccc[LANGCANTREADDESTINATION], "Error: Unable to read from destination");
  strcpy(enlang_ccc[LANGDRIVERMODE1BUTTON], "Virtual\nMode 1");
  strcpy(enlang_ccc[LANGDRIVERMODE2BUTTON], "Virtual\nMode 2");
  strcpy(enlang_ccc[LANGDRIVERMODE3BUTTON], "Virtual\nMode 3");
  strcpy(enlang_ccc[LANGDRIVERMODE4BUTTON], "Virtual\nMode 4");
  strcpy(enlang_ccc[LANGDRIVERMODE5BUTTON], "Virtual\nMode 5");
  strcpy(enlang_ccc[LANGDRIVERMODE1], "Mode 1");
  strcpy(enlang_ccc[LANGDRIVERMODE2], "Mode 2");
  strcpy(enlang_ccc[LANGDRIVERMODE3], "Mode 3");
  strcpy(enlang_ccc[LANGDRIVERMODE4], "Mode 4");
  strcpy(enlang_ccc[LANGDRIVERMODE5], "Mode 5");
  strcpy(enlang_ccc[LANGERRORDRIVERSECTORSIZE], "Error: Odd sector size not allowed in driver mode");
  strcpy(enlang_ccc[LANGERRORDRIVERSTOPPEDERROR], "Error: Driver timeout or error");
  strcpy(enlang_ccc[LANGHARDRESETBUTTON], "Soft\nReset");
  strcpy(enlang_ccc[LANGSOFTRESETBUTTON], "Hard\nReset");
  strcpy(enlang_ccc[LANGWARNINGNULLDRIVER], "Warning! Using driver mode with destination of null will clear the current progress log.\nOnce you click on Start, the log will be cleared.\nIf you wish to keep the current log, disconnect and make a copy.");
  strcpy(enlang_ccc[LANGINSTALLDRIVER], "Start Virtual Disk Driver");
  strcpy(enlang_ccc[LANGUNINSTALLDRIVER], "Stop Virtual Disk Driver");
  strcpy(enlang_ccc[LANGSLOWSKIPLABEL], "Slow skips");
  strcpy(enlang_ccc[LANGLASTREADSIZELABEL], "Last read size");
  strcpy(enlang_ccc[LANGDOMAINBLOCKNOTFOUND], "Internal program error, Position not found in domain");
  strcpy(enlang_ccc[LANGDRIVERONLYMI], "Virtual Driver only");
  strcpy(enlang_ccc[LANGNEWDOMAINFILE], "New Domain File");
  strcpy(enlang_ccc[LANGSAVEDOMAINFILEAS], "Save Domain File As");
  strcpy(enlang_ccc[LANGSAVEDOMAINFILE], "Save Domain File");
  strcpy(enlang_ccc[LANGLOADACTIVATIONFILE], "Load Activation File");
  strcpy(enlang_ccc[LANGACTIVATIONFAILED], "Activation Failed");
  strcpy(enlang_ccc[LANGACTIVATIONSUCCESS], "Activation Successful.\nYou must restart the program for the changes to take effect.");
  strcpy(enlang_ccc[LANGCONFIRMOPERATION], "Confirm Operation");
  strcpy(enlang_ccc[LANGCONFIRMREMOVEACTIVATION], "Do you wish to remove the activation?");
  strcpy(enlang_ccc[LANGREMOVEACTIVATION], "Remove Activation");
  strcpy(enlang_ccc[LANGOPERATIONFAILED], "Operation Failed\n");
  strcpy(enlang_ccc[LANGOPERATIONSUCCEEDED], "Operation completed successfully\n");
  strcpy(enlang_ccc[LANGDRIVELOCKED], "Error! The disk is security locked!");
  strcpy(enlang_ccc[LANGDISABLEPORTS], "Disable Ports");
  strcpy(enlang_ccc[LANGUNABLETOOPEN], "Error: Unable to open file");
  strcpy(enlang_ccc[LANGNOBACKUPFILE], "Error: No backup file");
  strcpy(enlang_ccc[LANGDISABLEPORTSINFO1], "Disable ports for AHCI mode to hide a drive from the operating system.\n"
                                            "Warning! If you disable the port for the operating system drive,\n"
                                            "the system will not be able to boot!\n");
  strcpy(enlang_ccc[LANGDISABLEPORTSINFO2], "Enter the ports you wish to be disabled as integers separated by spaces.\n"
                                            "It is best that the port numbers are in order from lowest to highest.\n"
                                            "You can find port information by listing source drives in AHCI mode.\n");
  strcpy(enlang_ccc[LANGCURRENTDISPORTS], "Current disabled ports (GRUB data)");
  strcpy(enlang_ccc[LANGSETDISPORTS], "Set disabled ports");
  strcpy(enlang_ccc[LANGUPDATEDDISPORTS], "Updated disabled ports (GRUB data)");
  strcpy(enlang_ccc[LANGUPDATEPORTS], "Update ports");
  strcpy(enlang_ccc[LANGCOPYFAILED], "Error: File copying failed");
  strcpy(enlang_ccc[LANGUPDATEGRUBFAILED], "Error: Updating GRUB failed");
  strcpy(enlang_ccc[LANGSEETERMOUTPUT], "See the terminal console output for more information");
  strcpy(enlang_ccc[LANGNOGRUBDEFAULTLINE], "Error: Unable to locate the line in GRUB");
  strcpy(enlang_ccc[LANGCONFIRMGRUBUPDATE], "You are about to make a change to the startup configuration.\nA reboot will be required for the changes to take effect.");
  strcpy(enlang_ccc[LANGRESTOREPORTS], "Restore original startup port configuration");
  strcpy(enlang_ccc[LANGENABLESCSIWRITE], "Enable SCSI write to destination (for odd sector size)");
  strcpy(enlang_ccc[LANGENABLEOUTPUTSECTORSIZE], "Enable output sector size adjustment");
  strcpy(enlang_ccc[LANGOUTPUTSECTORSIZE], "Output sector size adjustment");
  strcpy(enlang_ccc[LANGDRIVEROUTPUTOPTIONS], "Virtual Disk Device Driver output options for read errors");
  strcpy(enlang_ccc[LANGDRIVERRETURNERROR], "Return read error (standard)");
  strcpy(enlang_ccc[LANGDRIVERRETURNZEROS], "Return zero filled data");
  strcpy(enlang_ccc[LANGDRIVERRETURNMARKED], "Return mark filled data");
  strcpy(enlang_ccc[LANGVIRTUALMINCLUSTER], "Virtual Disk minimum cluster read size (mode 3)");
  strcpy(enlang_ccc[LANGVIRTUALNAME], "Virtual Disk device name");
  strcpy(enlang_ccc[LANGMISSINGDRIVER], "The virtual disk device driver is not running");
  strcpy(enlang_ccc[LANGCONFIRMERASEDESTINATION], "You are about to erase all data on the destination!\nAre you sure you want to erase all data?");
  strcpy(enlang_ccc[LANGANALYZE], "Analyze");
  strcpy(enlang_ccc[LANGRESULTS], "Results");
  strcpy(enlang_ccc[LANGTOTALGOODBADLABEL], "Total, Good, Bad, Slow");
  strcpy(enlang_ccc[LANGENABLEEXTENDEDANALYZE], "Enable extended analyze");
  strcpy(enlang_ccc[LANGIDLE], "Idle");
  strcpy(enlang_ccc[LANGPHASE1], "Phase 1");
  strcpy(enlang_ccc[LANGPHASE2], "Phase 2");
  strcpy(enlang_ccc[LANGPHASE3], "Phase 3");
  strcpy(enlang_ccc[LANGPHASE4], "Phase 4");
  strcpy(enlang_ccc[LANGTRIMMING], "Trimming");
  strcpy(enlang_ccc[LANGDIVIDING1], "Dividing 1");
  strcpy(enlang_ccc[LANGDIVIDING2], "Dividing 2");
  strcpy(enlang_ccc[LANGSCRAPING], "Scraping");
  strcpy(enlang_ccc[LANGFINISHED], "Finished");
  strcpy(enlang_ccc[LANGRETRYING], "Retrying");
  strcpy(enlang_ccc[LANGFILLING], "Filling");
  strcpy(enlang_ccc[LANGERASEING], "Erasing");
  strcpy(enlang_ccc[LANGBADHEAD], "(Bad Head)");
  strcpy(enlang_ccc[LANGREADINGDESTINATION], "Reading destination");
  strcpy(enlang_ccc[LANGREADING], "Reading: ");
  strcpy(enlang_ccc[LANGANALYZING], "Analyzing");
  strcpy(enlang_ccc[LANGDETECTINGVARIANCE], "Detecting Variance");
  strcpy(enlang_ccc[LANGREVERSE], "(Reverse)");
  strcpy(enlang_ccc[LANGDRIVERALREADYINSTALLED], "The driver is already installed and active\n");
  strcpy(enlang_ccc[LANGDRIVERMEMORYCONNECTED], "The driver memory is now connected\n");
  strcpy(enlang_ccc[LANGERRORCONNECTINGDRIVER], "Error connecting to driver memory\n");
  strcpy(enlang_ccc[LANGCANNOTOPENFORWRITING], "Cannot open for writing");
  strcpy(enlang_ccc[LANGMAKEFAILED], "Make failed, see the console for more information");
  strcpy(enlang_ccc[LANGFAILEDTOINSTALLDRIVER], "Failed to install driver module, see the console for more information");
  strcpy(enlang_ccc[LANGDRIVERINSTALLSUCCESS], "Driver install success\n");
  strcpy(enlang_ccc[LANGFAILEDTOREMOVEDRIVER], "Failed to remove driver module, see the console for more information");
  strcpy(enlang_ccc[LANGDRIVERREMOVALSUCCESS], "Driver removal success\n");
  strcpy(enlang_ccc[LANGVARIANCEREADTIMES], "Variance read times low/high:");
  strcpy(enlang_ccc[LANGZONE], "Zone");
  strcpy(enlang_ccc[LANGTOTAL], "Total");
  strcpy(enlang_ccc[LANGGOOD], "Good");
  strcpy(enlang_ccc[LANGBAD], "Bad");
  strcpy(enlang_ccc[LANGLOW], "Low");
  strcpy(enlang_ccc[LANGHIGH], "High");
  strcpy(enlang_ccc[LANGAVERAGE], "Average");
  strcpy(enlang_ccc[LANGZONES], "Zones");
  strcpy(enlang_ccc[LANGDISPLAYANALYZERESULTS], "Display Analyze Results");
  strcpy(enlang_ccc[LANGSKIPRESET], "Error: Skip Reset detected. The settings may need to be changed.\nSkip size may be too low or too high.\nThe drive may have a slow issue causing too many slow skips.\nIf you got this message very quickly, it may not be reading any data.\n Please reference the instruction manual for more information.");
  strcpy(enlang_ccc[LANGHELPHTML], "Instruction Manual HTML");
  strcpy(enlang_ccc[LANGHELPTEXT], "Instruction Manual TEXT");
  strcpy(enlang_ccc[LANGSMARTNOTSUPPORTED], "Error: SMART not supported on this device");
  strcpy(enlang_ccc[LANGSMARTNOTENABLED], "Error: SMART not enabled on this device");
  strcpy(enlang_ccc[LANGERRORREADINGSMART], "Error: Unable to read SMART data from device");
  strcpy(enlang_ccc[LANGID], "ID");
  strcpy(enlang_ccc[LANGFLAGS], "Flags");
  strcpy(enlang_ccc[LANGCURRENT], "Current");
  strcpy(enlang_ccc[LANGWORST], "Worst");
  strcpy(enlang_ccc[LANGTHRESHOLD], "Threshold");
  strcpy(enlang_ccc[LANGRAWDATA], "Raw data");
  strcpy(enlang_ccc[LANGATTRIBUTENAME], "Attribute name");
  strcpy(enlang_ccc[LANGSMARTVERSION], "SMART data structure version");
  strcpy(enlang_ccc[LANGSMART], "SMART");
  strcpy(enlang_ccc[LANGDISPLAYSMARTRESULTS], "Display SMART Results");
  strcpy(enlang_ccc[LANGCONFIRMIMAGEFILE], "The image file currently exists.\nThis will continue the recovery using this image file.");
  strcpy(enlang_ccc[LANGUSEPHYSICALSECTORSIZE], "Use physical sector size as logical for virtual disk");
  strcpy(enlang_ccc[LANGAGRESSIVEDRIVERBUTTON], "Slow\nDriver");
  strcpy(enlang_ccc[LANGUSECOLORSTATUSBAR], "Use button colors in bottom status bar");
  strcpy(enlang_ccc[LANGPRIMARYRELAY], "Primary Relay Settings");
  strcpy(enlang_ccc[LANGPRIMARYRELAYINFO], "Primary relay board settings");
  strcpy(enlang_ccc[LANGCURRENTRELAY], "Current relay board");
  strcpy(enlang_ccc[LANGCHOOSEPRIMARYUSB], "Choose Primary Relay Board");
  strcpy(enlang_ccc[LANGRELAYBOARDSETTINGS], "Relay board settings");
  strcpy(enlang_ccc[LANGRELAYACTIVATION], "Activation condition");
  strcpy(enlang_ccc[LANGACTIVATERELAY1], "Energize relay 1");
  strcpy(enlang_ccc[LANGACTIVATERELAY2], "Energize relay 2");
  strcpy(enlang_ccc[LANGACTIVATERELAY3], "Energize relay 3");
  strcpy(enlang_ccc[LANGACTIVATERELAY4], "Energize relay 4");
  strcpy(enlang_ccc[LANGACTIVATERELAY5], "Energize relay 5");
  strcpy(enlang_ccc[LANGACTIVATERELAY6], "Energize relay 6");
  strcpy(enlang_ccc[LANGACTIVATERELAY7], "Energize relay 7");
  strcpy(enlang_ccc[LANGACTIVATERELAY8], "Energize relay 8");
  strcpy(enlang_ccc[LANGRELAYDEACTIVATION], "Deactivation condition");
  strcpy(enlang_ccc[LANGRELAYACTIVATETIME], "Activation time (sec)");
  strcpy(enlang_ccc[LANGRELAYDELAYTIME], "Post activation delay time (sec)");
  strcpy(enlang_ccc[LANGTESTRELAYBUTTON], "Test relay operation");
  strcpy(enlang_ccc[LANGCHOOSEUSB], "Choose USB Relay");
  strcpy(enlang_ccc[LANGUSBERROR], "Error choosing USB relay");
  strcpy(enlang_ccc[LANGUSBRELAYERROR], "Error operating relay, see console for more information");
  strcpy(enlang_ccc[LANGNORELAYCHOSEN], "Error: No relay has been chosen");
  strcpy(enlang_ccc[LANGPRIMARYRELAYONERROR], "Activate primary relay");
  strcpy(enlang_ccc[LANGCYCLEPRIMARYRELAY], "Activate primary relay");
  strcpy(enlang_ccc[LANGACTIVATE], "Activate (Power Off)");
  strcpy(enlang_ccc[LANGDEACTIVATE], "Deactivate (Power On)");
  strcpy(enlang_ccc[LANGACTIVATEMAIN], "Power Off");
  strcpy(enlang_ccc[LANGDEACTIVATEMAIN], "Power On");
  strcpy(enlang_ccc[LANGUNSUPPORTEDSECTORSIZE], "This sector size is not supported for the selected mode in the free version. \nGeneric mode is the only mode in the free version to allow a different sector size than 512 or 4096.\n");
  strcpy(enlang_ccc[LANGRESCUEFAILED], "The rescue failed to finish");
  strcpy(enlang_ccc[LANGRESCUEFAILEDERROR], "The rescue has stopped before completion.\nStop code = ");
  strcpy(enlang_ccc[LANGDISPLAYIDENTIFYRESULTS], "Display Identify Results");
  strcpy(enlang_ccc[LANGMODEUSB], "Direct USB");
  strcpy(enlang_ccc[LANGUSBRESETS], "USB reset choices");
  strcpy(enlang_ccc[LANGENABLEUSBBULKRESET], "Enable USB bulk reset");
  strcpy(enlang_ccc[LANGENABLEUSBSOFTRESET], "Enable USB soft reset");
  strcpy(enlang_ccc[LANGENABLEUSBHARDRESET], "Enable USB hard reset");
  strcpy(enlang_ccc[LANGENABLEUSBPORTRESET], "Enable USB port reset");
  strcpy(enlang_ccc[LANGUSBMASSDISABLE], "You are about to disable the USB mass storage driver,\nafter which no USB storage devices will be detected by the operating system.");
  strcpy(enlang_ccc[LANGUSBMASSRESTORE], "You are about to restore the USB mass storage driver.");
  strcpy(enlang_ccc[LANGDISABLEUSBMASS], "Disable USB mass storage driver");
  strcpy(enlang_ccc[LANGRESTOREUSBMASS], "Restore USB mass storage driver");
  strcpy(enlang_ccc[LANGDESTINATIONTOOSMALL], "Warning! The destination is smaller than the source.\nSome data may not be copied.");
  strcpy(enlang_ccc[LANGENABLEREADTWICE], "Enable read twice on timeout");
  strcpy(enlang_ccc[LANGMODEUSBATA], "Direct USB ATA");
  strcpy(enlang_ccc[LANGADDDOMAINFILE], "Add to Domain from DMDE bytes file");
  strcpy(enlang_ccc[LANGNODOMAIN], "Error: Domain is not active or no domain file loaded");
  strcpy(enlang_ccc[LANGALWAYSWAITRESETTIME], "Always wait for reset timers");
  strcpy(enlang_ccc[LANGENABLECURRENTPOSITION], "Enable changing current position (can affect skipping algorithm)");
  strcpy(enlang_ccc[LANGIOSCSIONLY], "Virtual Disk IO SCSI only");
  strcpy(enlang_ccc[LANGSLOW], "Slow");
  strcpy(enlang_ccc[LANGSLOWRESPONDINGISSUE], "Slow Responding Firmware Issue");
  strcpy(enlang_ccc[LANGPARTIALACCESSISSUE], "Partial Access Issue");
  strcpy(enlang_ccc[LANGBADORWEAKHEAD], "Bad Or Weak Head");
  strcpy(enlang_ccc[LANGANALYZELONG], "Extended\nAnalyze");
  strcpy(enlang_ccc[LANGENABLEREBUILDASSIST], "Enable Rebuild Assist");
  strcpy(enlang_ccc[LANGREBUILDASSIST], "Rebuild Assist");
  strcpy(enlang_ccc[LANGREBUILDASSISTAHCIONLY], "Rebuild assist only works in direct ahci mode");
  strcpy(enlang_ccc[LANGREBUILDASSISTNOTSUPPORTED], "Rebuild assist is not supported on this device");
  strcpy(enlang_ccc[LANGREBUILDASSISTERRORDISABLING], "Error disabling rebuild assist");
  strcpy(enlang_ccc[LANGREBUILDASSISTERRORENABLING], "Error enabling rebuild assist");
  strcpy(enlang_ccc[LANGSELECTLUN], "Select Logical Unit");
  strcpy(enlang_ccc[LANGSELECTLUNINFO], "This device has more than 1 logical unit.\nPlease choose which logical unit.");
  strcpy(enlang_ccc[LANGLUNVALUES], "Possible Logical Units");
  strcpy(enlang_ccc[LANGSETLUN], "Set Logical Unit");
  strcpy(enlang_ccc[LANGFIXDRIVERMEMORYERROR], "Fix Driver Memory Error");
  strcpy(enlang_ccc[LANGENABLERETRYCONNECTING], "Retry connecting on failure after relay power cycle");
  strcpy(enlang_ccc[LANGMAXREADRATE], "Max read rate (kB/s)");
  strcpy(enlang_ccc[LANGDONTIDENTIFY], "Do not perform identify when listing source devices");
  // strcpy (enlang_ccc[], "");
  // strcpy (enlang_ccc[], "");
  // strcpy (enlang_ccc[], "");

  return 0;
}