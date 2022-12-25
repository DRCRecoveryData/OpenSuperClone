// Copyright (C) Scott Dwyer and OpenSuperClone contributors.
// You may use/distribute/modify this freely, under the terms of
// the GNU General Public License version 2 or later version.
// This software is distributed WITHOUT ANY WARRANTY.

#include "config.h"
#include "clone_gui_common.h"
#include "clone_gui.h"
#include "common.h"
#include "opensuperclone_glade.h"

int start_gtk_ccc(int argc, char **argv, char *title, char *version)
{
  // initialize memory so it is ready
  return_value_ccc = initialize_logfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
    return -1;
  }
  return_value_ccc = initialize_domainfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
    return -1;
  }
  return_value_ccc = initialize_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
    return -1;
  }

  char window_title[256];
  snprintf(window_title, sizeof(window_title), "%s %s", title, version);

  gtk_init(&argc, &argv);

  if (enable_data_dump_ccc || enable_dump_identify_on_check_ccc)
  {
    set_data_dump_filename_ccc();
    char temp_string[256];
    dump_info_to_filename_ccc(data_dump_filename_ccc, "*****************************************************************\n");
    snprintf(temp_string, sizeof(temp_string), "********** %s %s data dump file **********\n", title_ccc, version_number_ccc);
    dump_info_to_filename_ccc(data_dump_filename_ccc, temp_string);
  }

  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }

  main_window_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));
  if (NULL == main_window_ccc)
  {
    fprintf(stderr, "Object error: window_main \n");
  }

  bottom_status_bar_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "bottom_status_bar"));

  gtk_builder_connect_signals(builder, NULL);

  gtk_window_set_title(GTK_WINDOW(main_window_ccc), window_title);

  topmenubar_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "topmenubar"));
  filemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "filemi"));
  quitmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "quitmi"));
  openmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "openmi"));
  newmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "newmi"));
  sourcemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "sourcemi"));
  destinationmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "destinationmi"));
  drivesmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "drivesmi"));
  blockmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "blockmi"));
  drivemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "drivemi"));
  imagemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "imagemi"));
  devnullmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "devnullmi"));
  modemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "modemi"));
  copyimagemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "copyimagemi"));
  genericmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "genericmi"));
  pass_automi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "pass_automi"));
  pass_scsimi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "pass_scsimi"));
  pass_atrami_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "pass_atami"));
  directmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "directmi"));
  ahcimi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "ahcimi"));
  usbmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "usbmi"));
  usbatami_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "usbatami"));
  settingsmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "settingsmi"));
  advancedmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "advancedmi"));
  clonemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "clonemi"));
  savemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "savemi"));
  saveasmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "saveasmi"));
  resetstatusmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "resetstatusmi"));
  toolsmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "toolsmi"));
  resetlogmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "resetlogmi"));
  repairlogmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "repairlogmi"));
  fillzeromi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "fillzeromi"));
  fillmarkmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "fillmarkmi"));
  fillerasemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "fillerasemi"));
  domainmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "domainmi"));
  importddmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "importddmi"));
  exportddmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "exportddmi"));
  label_project_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_project"));
  data_project_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_project"));
  label_domain_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_domain"));
  data_domain_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_domain"));
  label_source_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_source"));
  data_source_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_source"));
  label_destination_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_destination"));
  data_destination_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_destination"));
  label_totallba_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_totallba"));
  data_totallba_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_totallba"));
  label_lbatoread_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_lbatoread"));
  data_lbatoread_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_lbatoread"));
  label_domainsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_domainsize"));
  data_domainsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_domainsize"));
  label_runtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_runtime"));
  data_runtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_runtime"));
  label_remainingtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_remainingtime"));
  data_remainingtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_remainingtime"));
  label_currentposition_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_currentposition"));
  data_currentposition_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_currentposition"));
  label_currentstatus_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_currentstatus"));
  data_currentstatus_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_currentstatus"));
  label_currentrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_currentrate"));
  data_currentrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_currentrate"));
  label_recentrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_recentrate"));
  data_recentrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_recentrate"));
  label_totalrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_totalrate"));
  data_totalrate_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_totalrate"));
  label_skipsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_skipsize"));
  data_skipsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_skipsize"));
  label_skips_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_skips"));
  data_skips_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_skips"));
  label_slowskips_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_slowskips"));
  data_slowskips_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_slowskips"));
  label_skipruns_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_skipruns"));
  data_skipruns_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_skipruns"));
  label_skipresets_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_skipresets"));
  data_skipresets_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_skipresets"));
  label_runsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_runsize"));
  data_runsize_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_runsize"));
  label_finished_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_finished"));
  data_finished_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_finished"));
  label_nontried_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_nontried"));
  data_nontried_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_nontried"));
  label_nontrimmed_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_nontrimmed"));
  data_nontrimmed_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_nontrimmed"));
  label_nondivided_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_nondivided"));
  data_nondivided_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_nondivided"));
  label_nonscraped_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_nonscraped"));
  data_nonscraped_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_nonscraped"));
  label_bad_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_bad"));
  data_bad_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_bad"));
  label_datapreview_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_datapreview"));
  data_datapreview_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_datapreview"));
  label_longestreadtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_longestreadtime"));
  data_longestreadtime_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_longestreadtime"));
  label_filled_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_filled"));
  data_filled_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_filled"));
  label_retried_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_retried"));
  data_retried_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_retried"));
  label_retrypasses_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_retrypasses"));
  data_retrypasses_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_retrypasses"));
  cleardomainmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "cleardomainmi"));
  helpmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "helpmi"));
  aboutmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "aboutmi"));
  timermi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "timermi"));
  label_drivermode_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_drivermode"));
  data_drivermode_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_drivermode"));
  installdrivermi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "installdrivermi"));
  uninstalldrivermi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "uninstalldrivermi"));
  fixdrivermemorymi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "fixdrivermemorymi"));
  driveronlymi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driveronlymi"));
  adddomainmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "adddomainmi"));
  newdomainmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "newdomainmi"));
  savedomainmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "savedomainmi"));
  savedomainasmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "savedomainasmi"));
  activatewithfilemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activatewithfilemi"));
  removeactivationmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "removeactivationmi"));
  disableportsmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disableportsmi"));
  restoreportsmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "restoreportsmi"));
  displayidentifymi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "displayidentifymi"));
  displayanalyzemi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "displayanalyzemi"));
  displaysmartmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "displaysmartmi"));
  primaryrelaymi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primaryrelaymi"));
  chooseprimaryrelaymi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "chooseprimaryrelaymi"));
  disableusbmassmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disableusbmassmi"));
  restoreusbmassmi_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "restoreusbmassmi"));
  activate_primary_relay_button_main_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay_button_main"));
  deactivate_primary_relay_button_main_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay_button_main"));

  gtk_menu_item_set_label(GTK_MENU_ITEM(filemi_ccc), _("File"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(openmi_ccc), _("Open Project"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(newmi_ccc), _("New Project"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(quitmi_ccc), _("Quit"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(sourcemi_ccc), _("Choose Source Drive"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(destinationmi_ccc), _("Choose Destination"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(blockmi_ccc), _("Generic block device"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(drivemi_ccc), _("Drive"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(drivesmi_ccc), _("Drives"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(imagemi_ccc), _("Image file"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(devnullmi_ccc), _("NULL (No destination)"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(modemi_ccc), _("Mode"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(copyimagemi_ccc), _("Generic source file"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(genericmi_ccc), _("Generic source device"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(pass_automi_ccc), _("Passthrough auto detect"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(pass_scsimi_ccc), _("Passthrough SCSI"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(pass_atrami_ccc), _("Passthrough ATA"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(directmi_ccc), _("Direct IDE"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(ahcimi_ccc), _("Direct AHCI"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(usbmi_ccc), _("Direct USB"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(usbatami_ccc), _("Direct USB ATA"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(settingsmi_ccc), _("Settings"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(advancedmi_ccc), _("Advanced Settings"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(clonemi_ccc), _("Clone Settings"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(savemi_ccc), _("Save Project"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(saveasmi_ccc), _("Save Project As"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(resetstatusmi_ccc), _("Reset Current Status"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(toolsmi_ccc), _("Tools"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(resetlogmi_ccc), _("Reset Log"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(repairlogmi_ccc), _("Repair Log"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(fillzeromi_ccc), _("Fill Zero"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(fillmarkmi_ccc), _("Fill Mark"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(fillerasemi_ccc), _("Erase Destination"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(domainmi_ccc), _("Load Domain File"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(importddmi_ccc), _("Import ddrescue log (map) file"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(exportddmi_ccc), _("Export ddrescue log (map) file"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(cleardomainmi_ccc), _("Clear Domain"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(helpmi_ccc), _("Help"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(aboutmi_ccc), _("About"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(timermi_ccc), _("Timer Settings"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(installdrivermi_ccc), _("Start Virtual Disk Driver"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(uninstalldrivermi_ccc), _("Stop Virtual Disk Driver"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(fixdrivermemorymi_ccc), _("Fix Driver Memory Error"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(driveronlymi_ccc), _("Virtual Driver only"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(adddomainmi_ccc), _("Add to Domain from DMDE bytes file"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(newdomainmi_ccc), _("New Domain File"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(savedomainmi_ccc), _("Save Domain File"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(savedomainasmi_ccc), _("Save Domain File As"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(disableportsmi_ccc), _("Disable Ports"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(restoreportsmi_ccc), _("Restore original startup port configuration"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(displayidentifymi_ccc), _("Display Identify Results"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(displayanalyzemi_ccc), _("Display Analyze Results"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(displaysmartmi_ccc), _("Display SMART Results"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(primaryrelaymi_ccc), _("Primary Relay Settings"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(chooseprimaryrelaymi_ccc), _("Choose Primary Relay Board"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(disableusbmassmi_ccc), _("Disable USB mass storage driver"));
  gtk_menu_item_set_label(GTK_MENU_ITEM(restoreusbmassmi_ccc), _("Restore USB mass storage driver"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay_button_main_ccc), _("Power Off"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay_button_main_ccc), _("Power On"));

  // add tooltips for relay buttons
  gtk_widget_set_tooltip_text(activate_primary_relay_button_main_ccc, _("Power off the drive with the selected relay board"));
  gtk_widget_set_tooltip_text(deactivate_primary_relay_button_main_ccc, _("Power on the drive with the selected relay board"));

  // add keyboard shortcuts
  GtkAccelGroup *accel_group = gtk_accel_group_new();
  gtk_window_add_accel_group(GTK_WINDOW(main_window_ccc), accel_group);

  gtk_widget_add_accelerator(openmi_ccc, "activate", accel_group, GDK_KEY_O, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(savemi_ccc, "activate", accel_group, GDK_KEY_S, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(saveasmi_ccc, "activate", accel_group, GDK_KEY_S, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(quitmi_ccc, "activate", accel_group, GDK_KEY_Q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(newmi_ccc, "activate", accel_group, GDK_KEY_N, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  // gtk_widget_add_accelerator(importddmi_ccc, "activate", accel_group, GDK_KEY_I, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
  // gtk_widget_add_accelerator(exportddmi_ccc, "activate", accel_group, GDK_KEY_E, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

  gtk_widget_add_accelerator(domainmi_ccc, "activate", accel_group, GDK_KEY_D, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(newdomainmi_ccc, "activate", accel_group, GDK_KEY_N, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(cleardomainmi_ccc, "activate", accel_group, GDK_KEY_C, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
  // gtk_widget_add_accelerator(adddomainmi_ccc, "activate", accel_group, GDK_KEY_M, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator(savedomainmi_ccc, "activate", accel_group, GDK_KEY_E, GDK_CONTROL_MASK | GDK_SHIFT_MASK, GTK_ACCEL_VISIBLE);

  main_label = GTK_WIDGET(gtk_builder_get_object(builder, "main_label"));

  connect_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "connect_button"));
  disconnect_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disconnect_button"));
  start_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "start_button"));
  stop_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "stop_button"));
  analyze_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "analyze_button"));
  analyze_long_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "analyze_long_button"));
  smart_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "smart_button"));
  clone_mode_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "clone_mode_button"));
  driver_mode1_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_mode1_button"));
  agressive_driver_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "agressive_driver_checkbutton"));
  driver_mode2_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_mode2_button"));
  driver_mode3_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_mode3_button"));
  driver_mode4_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_mode4_button"));
  driver_mode5_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_mode5_button"));
  soft_reset_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "soft_reset_button"));
  hard_reset_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "hard_reset_button"));

  gtk_button_set_label(GTK_BUTTON(connect_button_ccc), _("Connect"));
  gtk_button_set_label(GTK_BUTTON(disconnect_button_ccc), _("Disconnect"));
  gtk_button_set_label(GTK_BUTTON(start_button_ccc), _("Start"));
  gtk_button_set_label(GTK_BUTTON(stop_button_ccc), _("Stop"));
  gtk_button_set_label(GTK_BUTTON(analyze_button_ccc), _("Analyze"));
  gtk_button_set_label(GTK_BUTTON(analyze_long_button_ccc), _("Extended\nAnalyze"));
  gtk_button_set_label(GTK_BUTTON(smart_button_ccc), _("SMART"));
  gtk_button_set_label(GTK_BUTTON(clone_mode_button_ccc), _("Clone\nMode"));
  gtk_button_set_label(GTK_BUTTON(agressive_driver_checkbutton_ccc), _("Slow\nDriver"));
  gtk_button_set_label(GTK_BUTTON(driver_mode1_button_ccc), _("Virtual\nMode 1"));
  gtk_button_set_label(GTK_BUTTON(driver_mode2_button_ccc), _("Virtual\nMode 2"));
  gtk_button_set_label(GTK_BUTTON(driver_mode3_button_ccc), _("Virtual\nMode 3"));
  gtk_button_set_label(GTK_BUTTON(driver_mode4_button_ccc), _("Virtual\nMode 4"));
  gtk_button_set_label(GTK_BUTTON(driver_mode5_button_ccc), _("Virtual\nMode 5"));
  gtk_button_set_label(GTK_BUTTON(soft_reset_button_ccc), _("Soft\nReset"));
  gtk_button_set_label(GTK_BUTTON(hard_reset_button_ccc), _("Hard\nReset"));

  // set button tooltips
  gtk_widget_set_tooltip_text(connect_button_ccc, _("Connect to the drive"));
  gtk_widget_set_tooltip_text(disconnect_button_ccc, _("Disconnect from the drive"));
  gtk_widget_set_tooltip_text(start_button_ccc, _("Start the clone/virtual driver"));
  gtk_widget_set_tooltip_text(stop_button_ccc, _("Stop the clone/virtual driver"));
  gtk_widget_set_tooltip_text(analyze_button_ccc, _("Analyze the drive"));
  gtk_widget_set_tooltip_text(analyze_long_button_ccc, _("Analyze the drive (extended)"));
  gtk_widget_set_tooltip_text(smart_button_ccc, _("Retrieve SMART information"));
  gtk_widget_set_tooltip_text(clone_mode_button_ccc, _("Switch to clone mode"));
  gtk_widget_set_tooltip_text(agressive_driver_checkbutton_ccc, _("Activate slow driver"));
  gtk_widget_set_tooltip_text(driver_mode1_button_ccc, _("Switch to virtual mode 1: This mode will use all available Phases (starting with Phase 4) when reading from the source"));
  gtk_widget_set_tooltip_text(driver_mode2_button_ccc, _("Switch to virtual mode 2: This mode will only use Phase 4 and will not perform any further processing of a chunk"));
  gtk_widget_set_tooltip_text(driver_mode3_button_ccc, _("Switch to virtual mode 3: This mode is the same as mode 2, but it will increase the read size (up to the cluster size) when it detects sequential reads"));
  gtk_widget_set_tooltip_text(driver_mode4_button_ccc, _("Switch to virtual mode 4: This mode only reads from the destination, and will not read any data from the source"));
  gtk_widget_set_tooltip_text(driver_mode5_button_ccc, _("Switch to virtual mode 5: This mode does not read any data and will instead return zeroed data"));
  gtk_widget_set_tooltip_text(soft_reset_button_ccc, _("Soft reset the drive"));
  gtk_widget_set_tooltip_text(hard_reset_button_ccc, _("Hard reset the drive"));

  gtk_label_set_text(GTK_LABEL(label_project_ccc), _("Project"));
  gtk_label_set_text(GTK_LABEL(label_domain_ccc), _("Domain"));
  gtk_label_set_text(GTK_LABEL(label_source_ccc), _("Source"));
  gtk_label_set_text(GTK_LABEL(label_destination_ccc), _("Destination (All data will be overwritten!)"));
  gtk_label_set_text(GTK_LABEL(label_totallba_ccc), _("Total LBA"));
  gtk_label_set_text(GTK_LABEL(label_lbatoread_ccc), _("LBA to read"));
  gtk_label_set_text(GTK_LABEL(label_domainsize_ccc), _("Domain size"));
  gtk_label_set_text(GTK_LABEL(label_runtime_ccc), _("Run time"));
  gtk_label_set_text(GTK_LABEL(label_remainingtime_ccc), _("Remaining time"));
  gtk_label_set_text(GTK_LABEL(label_currentposition_ccc), _("Current position"));
  gtk_label_set_text(GTK_LABEL(label_currentstatus_ccc), _("Current status"));
  gtk_label_set_text(GTK_LABEL(label_currentrate_ccc), _("Current rate"));
  gtk_label_set_text(GTK_LABEL(label_recentrate_ccc), _("Recent rate"));
  gtk_label_set_text(GTK_LABEL(label_totalrate_ccc), _("Total rate"));
  gtk_label_set_text(GTK_LABEL(label_skipsize_ccc), _("Base skip size"));
  gtk_label_set_text(GTK_LABEL(label_skips_ccc), _("Skips"));
  gtk_label_set_text(GTK_LABEL(label_slowskips_ccc), _("Slow skips"));
  gtk_label_set_text(GTK_LABEL(label_skipruns_ccc), _("Skip runs"));
  gtk_label_set_text(GTK_LABEL(label_skipresets_ccc), _("Skip resets"));
  gtk_label_set_text(GTK_LABEL(label_runsize_ccc), _("Last run size"));
  gtk_label_set_text(GTK_LABEL(label_finished_ccc), _("Finished"));
  gtk_label_set_text(GTK_LABEL(label_nontried_ccc), _("Non-Tried"));
  gtk_label_set_text(GTK_LABEL(label_nontrimmed_ccc), _("Non-Trimmed"));
  gtk_label_set_text(GTK_LABEL(label_nondivided_ccc), _("Non-Divided"));
  gtk_label_set_text(GTK_LABEL(label_nonscraped_ccc), _("Non-Scraped"));
  gtk_label_set_text(GTK_LABEL(label_bad_ccc), _("Bad"));
  gtk_label_set_text(GTK_LABEL(label_datapreview_ccc), _("Data preview"));
  gtk_label_set_text(GTK_LABEL(label_longestreadtime_ccc), _("Current / Recent / Longest"));
  gtk_label_set_text(GTK_LABEL(label_filled_ccc), _("Filled"));
  gtk_label_set_text(GTK_LABEL(label_retried_ccc), _("Retried"));
  gtk_label_set_text(GTK_LABEL(label_retrypasses_ccc), _("Remaining retry passes"));
  gtk_label_set_text(GTK_LABEL(label_drivermode_ccc), _("Clone/Driver Mode"));
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Clone"));

  // add label tooltips
  gtk_widget_set_tooltip_text(label_project_ccc, _("The project log file for the current recovery"));
  gtk_widget_set_tooltip_text(label_domain_ccc, _("The domain file for the current recovery"));
  gtk_widget_set_tooltip_text(label_source_ccc, _("The source drive to be recovered"));
  gtk_widget_set_tooltip_text(label_destination_ccc, _("The destination drive or image file to be recovered to"));
  gtk_widget_set_tooltip_text(label_totallba_ccc, _("The total number of LBAs in the source drive"));
  gtk_widget_set_tooltip_text(label_lbatoread_ccc, _("The number of LBAs to be read from the source drive"));
  gtk_widget_set_tooltip_text(label_domainsize_ccc, _("The size of the domain file in LBAs"));
  gtk_widget_set_tooltip_text(label_runtime_ccc, _("The total time taken to recover the drive"));
  gtk_widget_set_tooltip_text(label_remainingtime_ccc, _("The estimated time remaining to complete the recovery"));
  gtk_widget_set_tooltip_text(label_currentposition_ccc, _("The current position in the source drive in LBAs"));
  gtk_widget_set_tooltip_text(label_currentstatus_ccc, _("The current status of the recovery"));
  gtk_widget_set_tooltip_text(label_currentrate_ccc, _("The current rate of the recovery"));
  gtk_widget_set_tooltip_text(label_recentrate_ccc, _("The average rate of the last 5 minutes of the recovery"));
  gtk_widget_set_tooltip_text(label_totalrate_ccc, _("The average rate of the entire recovery"));
  gtk_widget_set_tooltip_text(label_skipsize_ccc, _("The base skip size"));
  gtk_widget_set_tooltip_text(label_skips_ccc, _("The total number of skips so far"));
  gtk_widget_set_tooltip_text(label_slowskips_ccc, _("The total number of skips due to slow reads so far"));
  gtk_widget_set_tooltip_text(label_skipruns_ccc, _("The total number of skip runs so far"));
  gtk_widget_set_tooltip_text(label_skipresets_ccc, _("The total number of times the skipping was reset due to exceeding the limit of 64 skips in a run"));
  gtk_widget_set_tooltip_text(label_runsize_ccc, _("The size of the last skip run"));
  gtk_widget_set_tooltip_text(label_finished_ccc, _("The total number of LBAs recovered so far"));
  gtk_widget_set_tooltip_text(label_nontried_ccc, _("The total number of LBAs that have not been tried to be recovered"));
  gtk_widget_set_tooltip_text(label_nontrimmed_ccc, _("The total number of LBAs that have not been trimmed"));
  gtk_widget_set_tooltip_text(label_nondivided_ccc, _("The total number of LBAs that have not been divided"));
  gtk_widget_set_tooltip_text(label_nonscraped_ccc, _("The total number of LBAs that have not been scraped"));
  gtk_widget_set_tooltip_text(label_bad_ccc, _("The total number of LBAs that have been marked as bad"));
  gtk_widget_set_tooltip_text(label_datapreview_ccc, _("A sample of data from the last good read since the last display update (will be all zeroes if no good reads have occurred since the last display update)"));
  gtk_widget_set_tooltip_text(label_longestreadtime_ccc, _("The longest read time since the last display update / within the last 256 display updates / since the start of the recovery"));
  gtk_widget_set_tooltip_text(label_filled_ccc, _("The total number of LBAs that have been filled either in Fill mode or Erase mode"));
  gtk_widget_set_tooltip_text(label_retried_ccc, _("The total number of LBAs that have been retried"));
  gtk_widget_set_tooltip_text(label_retrypasses_ccc, _("The total number of retry passes remaining"));
  gtk_widget_set_tooltip_text(label_drivermode_ccc, _("The current mode of the recovery"));

  // set status buttons
  button_bbk_ccc = gtk_button_new_with_label("BBK");
  button_unc_ccc = gtk_button_new_with_label("UNC");
  button_mc_ccc = gtk_button_new_with_label("MC");
  button_idnf_ccc = gtk_button_new_with_label("IDNF");
  button_mcr_ccc = gtk_button_new_with_label("MCR");
  button_abrt_ccc = gtk_button_new_with_label("ABRT");
  button_tk0nf_ccc = gtk_button_new_with_label("TK0NF");
  button_amnf_ccc = gtk_button_new_with_label("AMNF");
  button_bsy_ccc = gtk_button_new_with_label("BSY");
  button_drdy_ccc = gtk_button_new_with_label("DRDY");
  button_df_ccc = gtk_button_new_with_label("DF");
  button_dsc_ccc = gtk_button_new_with_label("DSC");
  button_drq_ccc = gtk_button_new_with_label("DRQ");
  button_corr_ccc = gtk_button_new_with_label("CORR");
  button_idx_ccc = gtk_button_new_with_label("IDX");
  button_err_ccc = gtk_button_new_with_label("ERR");
  button_status_separator_ccc = gtk_button_new_with_label("|");

  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_bsy_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_drdy_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_df_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_dsc_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_drq_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_corr_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_idx_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_err_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_status_separator_ccc, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_bbk_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_unc_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_mc_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_idnf_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_mcr_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_abrt_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_tk0nf_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(bottom_status_bar_ccc), button_amnf_ccc, TRUE, TRUE, 0);

  // set status buttons tooltips
  gtk_widget_set_tooltip_text(button_bsy_ccc, _("Busy (The device is busy)"));
  gtk_widget_set_tooltip_text(button_drdy_ccc, _("Device Ready (The device is ready to accept commands)"));
  gtk_widget_set_tooltip_text(button_df_ccc, _("Device Fault (The device has detected a fault)"));
  gtk_widget_set_tooltip_text(button_dsc_ccc, _("Device Seek Complete (Head is settled on the track)"));
  gtk_widget_set_tooltip_text(button_drq_ccc, _("Data Request (The device is ready to transfer data)"));
  gtk_widget_set_tooltip_text(button_corr_ccc, _("Corrected Data (The device has corrected data)"));
  gtk_widget_set_tooltip_text(button_idx_ccc, _("Index (The device has reached the index mark)"));
  gtk_widget_set_tooltip_text(button_err_ccc, _("Error (The device has detected an error)"));
  gtk_widget_set_tooltip_text(button_bbk_ccc, _("Bad Block (The device has detected a bad block)"));
  gtk_widget_set_tooltip_text(button_unc_ccc, _("Uncorrectable Data (The device has detected uncorrectable data)"));
  gtk_widget_set_tooltip_text(button_mc_ccc, _("Media Change (The media has changed)"));
  gtk_widget_set_tooltip_text(button_idnf_ccc, _("ID Not Found (The device could not find the sector's ID field)"));
  gtk_widget_set_tooltip_text(button_mcr_ccc, _("Media Change Request (The device has requested a media change)"));
  gtk_widget_set_tooltip_text(button_abrt_ccc, _("Command Aborted (The device has aborted the command)"));
  gtk_widget_set_tooltip_text(button_tk0nf_ccc, _("Track 0 Not Found (The device could not find track 0)"));
  gtk_widget_set_tooltip_text(button_amnf_ccc, _("Address Mark Not Found (The device could not find the address mark)"));

  // set intial button states
  set_disconnected_ccc();

  set_mode_auto_passthrough_ccc();

  if (scsi_passthrough_ccc || generic_mode_ccc)
  {
    deactivate_status_buttons_ccc();
  }
  else
  {
    activate_status_buttons_ccc();
  }

  g_object_unref(builder);

  gtk_window_set_default_size(main_window_ccc, 1075, 775);
  gtk_widget_show_all(main_window_ccc);
  gtk_main();

  return 0;
}

int set_data_dump_filename_ccc(void)
{
  language_window_ccc = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  // gtk_window_set_keep_above(GTK_WINDOW(language_window_ccc), TRUE);
  gtk_window_set_title(GTK_WINDOW(language_window_ccc), "Select Data Dump File");
  gtk_window_set_default_size(GTK_WINDOW(language_window_ccc), 400, 300);
  gtk_window_set_position(GTK_WINDOW(language_window_ccc), GTK_WIN_POS_CENTER);

  gint handler_id1 = g_signal_connect(G_OBJECT(language_window_ccc), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  GtkWidget *box = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(language_window_ccc), box);

  GtkWidget *enbutton = gtk_button_new_with_label("Continue");
  GtkWidget *imbutton = gtk_button_new_with_label("Change Data Dump File");
  GtkWidget *okim = gtk_image_new_from_stock(GTK_STOCK_OK, GTK_ICON_SIZE_BUTTON);
  GtkWidget *openim = gtk_image_new_from_stock(GTK_STOCK_OPEN, GTK_ICON_SIZE_BUTTON);
  gtk_button_set_image(GTK_BUTTON(enbutton), okim);
  gtk_button_set_image(GTK_BUTTON(imbutton), openim);

  gtk_box_pack_start(GTK_BOX(box), enbutton, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), imbutton, TRUE, TRUE, 0);

  gint handler_id2 = g_signal_connect(enbutton, "clicked", G_CALLBACK(gtk_main_quit), NULL);
  gint handler_id4 = g_signal_connect(imbutton, "clicked", G_CALLBACK(get_data_dump_filename_ccc), NULL);

  gtk_widget_show_all(language_window_ccc);
  gtk_main();
  g_signal_handler_disconnect(language_window_ccc, handler_id1);
  g_signal_handler_disconnect(enbutton, handler_id2);
  g_signal_handler_disconnect(imbutton, handler_id4);
  gtk_widget_hide(language_window_ccc);
  gtk_widget_destroy(language_window_ccc);

  return 0;
}

void get_data_dump_filename_ccc(void)
{
  GtkWidget *dialog;
  dialog = gtk_file_chooser_dialog_new("Select Data Dump File",
                                       GTK_WINDOW(language_window_ccc),
                                       GTK_FILE_CHOOSER_ACTION_SAVE,
                                       GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                       GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                       NULL);
  gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "debug_data_dump.log");
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;
    filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    fprintf(stdout, "%s\n", filename);
    strcpy(data_dump_filename_ccc, filename);
    g_free(filename);
  }
  gtk_widget_destroy(dialog);
}

int print_gui_error_message_ccc(char *message, char *title, int type)
{
  if (!superclone_ccc)
  {
    message_now_ccc(message);
  }
  else if (check_message_ccc && (do_call_command_ccc || activate_primary_relay_on_error_ccc))
  {
    g_print("%s\n", message);
  }
  else
  {
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *dialog;
    GtkDialogFlags message_type;
    if (type)
    {
      message_type = GTK_MESSAGE_WARNING;
      // dialog = gtk_message_dialog_new(GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_WARNING, GTK_BUTTONS_OK, "%s", message);
    }
    else
    {
      message_type = GTK_MESSAGE_INFO;
      // dialog = gtk_message_dialog_new(GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "%s", message);
    }
    dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, message_type, GTK_BUTTONS_OK, "%s", message);
    gtk_window_set_keep_above(GTK_WINDOW(dialog), TRUE);
    gtk_window_set_title(GTK_WINDOW(dialog), title);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(window);
  }

  check_message_ccc = false;
  return 0;
}

void select_file_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Load project (progress) file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      clear_source_ccc();
      clear_destination_ccc();
      project_chosen_ccc = 0;
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      load_log_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void new_file_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("New project (progress) file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      clear_source_ccc();
      clear_destination_ccc();
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      new_log_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void new_domain_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("New Domain File"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      new_domain_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void select_ddrescue_file_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (!new_project_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must start a new project before importing a ddrescue log file"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Import ddrescue log (map) file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      load_ddrescue_log_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void save_file_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    return_value_ccc = write_logfile_ccc(log_file_ccc, 0);
    if (return_value_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error writing progress log file"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
  }
}

void save_file_as_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Save Project File As"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      return_value_ccc = write_logfile_ccc(filename, 0);
      if (return_value_ccc)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error writing progress log file"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void save_domain_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    return_value_ccc = write_domainfile_ccc(domain_file_ccc, 0);
    if (return_value_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error writing progress log file"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
  }
}

void save_domain_as_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Save Domain File As"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      return_value_ccc = write_domainfile_ccc(filename, 0);
      if (return_value_ccc)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error writing progress log file"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void export_ddrescue_file_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Export ddrescue log (map) file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      return_value_ccc = write_ddrescue_logfile_ccc(filename);
      if (return_value_ccc)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error exporting ddrescue log (map) file"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void select_domain_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Load Domain File"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      load_domain_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

void add_domain_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (1 && !do_domain_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: Domain is not active or no domain file loaded"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Choose Destination Image"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      // load_domain_file_ccc(filename);
      add_domain_file_ccc(filename);
      g_free(filename);
    }
    gtk_widget_destroy(dialog);
  }
}

// Get the selected filename and load it
static void load_log_file_ccc(char *log_file)
{
  gtk_label_set_text(GTK_LABEL(main_label), "");
  // g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
  log_file_ccc = malloc(1024);
  memset(log_file_ccc, 0, 1024);
  strncpy(log_file_ccc, log_file, 1024);
  printf("%s\n", log_file_ccc);

  // initialize memory
  return_value_ccc = initialize_logfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
  }

  else
  {
    int ret = read_log_file_ccc(log_file_ccc);
    int ret2 = 0;
    if (ret != 0)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
    else
    {
      check_log_size_ccc = 0;
      ret = check_log_ccc();
      // if only same status then repair log automatically
      if (ret == 0x10)
      {
        ret2 = check_and_repair_log_ccc();
        clear_error_message_ccc();
        ret = check_log_ccc();
      }
      check_log_size_ccc = 1;
      if (ret != 0 || ret2 != 0)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Warning"), 1);
        clear_error_message_ccc();
      }

      project_chosen_ccc = 1;
      new_project_ccc = 0;
      data_read_from_log_ccc = 1;
      clear_destination_ccc();
      clear_source_ccc();
      set_initial_data_from_log_ccc(new_project_ccc);
      logfile_changed_ccc = true;
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    }
  }
}

// Get the selected ddrescue filename and load it
static void load_ddrescue_log_file_ccc(char *log_file)
{
  gtk_label_set_text(GTK_LABEL(main_label), "");
  // g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
  ddilog_file_ccc = malloc(1024);
  memset(ddilog_file_ccc, 0, 1024);
  strncpy(ddilog_file_ccc, log_file, 1024);
  printf("%s\n", ddilog_file_ccc);

  // initialize memory
  return_value_ccc = initialize_logfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
  }

  else
  {
    int ret = read_ddrescue_log_ccc(ddilog_file_ccc);
    int ret2 = 0;
    if (ret != 0)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
    else
    {
      importdd_ccc = true;
      ret = check_log_ccc();
      if (ret)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "There were errors found in the progress log file\n");
        message_now_ccc(tempmessage_ccc);
        ret2 = check_and_repair_log_ccc();
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "Checking the progress log file again to make sure it was fixed correctly.\n");
        message_now_ccc(tempmessage_ccc);
        ret = check_log_ccc();
        if (ret != 0 || ret2 != 0)
        {
          snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n"));
          message_error_ccc(tempmessage_ccc);
          print_gui_error_message_ccc(error_message_ccc, _("Warning"), 1);
          clear_error_message_ccc();
        }
      }
      importdd_ccc = false;

      project_chosen_ccc = 1;
      new_project_ccc = 0;
      clear_destination_ccc();
      clear_source_ccc();
      set_initial_data_from_log_ccc(new_project_ccc);
      logfile_changed_ccc = true;
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    }
  }
}

// Get the selected domain and load it
static void load_domain_file_ccc(char *log_file)
{
  gtk_label_set_text(GTK_LABEL(main_label), "");
  // g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
  clear_domain_ccc();
  strncpy(domain_file_ccc, log_file, 1024);
  printf("%s\n", domain_file_ccc);

  // initialize memory
  return_value_ccc = initialize_domainfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
  }

  else
  {
    int ret = read_domain_file_ccc(domain_file_ccc);
    if (ret < 0)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      do_domain_ccc = false;
    }
    else
    {
      do_domain_ccc = true;
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    }
  }
}

// Get the selected domain and load it
static void add_domain_file_ccc(char *log_file)
{
  gtk_label_set_text(GTK_LABEL(main_label), "");
  // g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
  printf("%s\n", log_file);

  int ret = read_domain_add_file_ccc(log_file);
  if (ret < 0)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  update_display_ccc(0);
}

void clear_domain_ccc(void)
{
  if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    initialize_domainfile_memory_ccc();
    if (domain_file_ccc != NULL)
    {
      free(domain_file_ccc);
    }
    domain_file_ccc = malloc(1024);
    memset(domain_file_ccc, 0, 1024);
    do_domain_ccc = false;
  }
  update_display_ccc(0);
}

// Get the selected filename and set it
static void new_log_file_ccc(char *log_file)
{
  log_file_ccc = malloc(1024);
  memset(log_file_ccc, 0, 1024);
  strncpy(log_file_ccc, log_file, 1024);
  printf("%s\n", log_file_ccc);

  clear_domain_ccc();
  strncpy(domain_file_ccc, log_file_ccc, 1016);
  strcat(domain_file_ccc, ".domain");
  remove(domain_file_ccc);
  clear_domain_ccc();

  // initialize memory
  return_value_ccc = initialize_logfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
  }
  project_chosen_ccc = 1;
  new_project_ccc = 1;
  data_read_from_log_ccc = 0;
  enable_extended_analyze_ccc = false;
  clear_destination_ccc();
  clear_source_ccc();
  clear_variables_for_new_project_ccc();
  initialize_new_log_ccc();
  logfile_changed_ccc = true;
  set_initial_data_from_log_ccc(new_project_ccc);
  logfile_changed_ccc = true;
  update_display_ccc(0);
  // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
}

static void new_domain_file_ccc(char *log_file)
{
  clear_domain_ccc();
  strncpy(domain_file_ccc, log_file, 1024);
  printf("%s\n", domain_file_ccc);

  // initialize memory
  return_value_ccc = initialize_domainfile_memory_ccc();
  if (return_value_ccc != 0)
  {
    exitcode_ccc = GENERAL_ERROR_EXIT_CODE;
  }
  initialize_domain_log_ccc();
  do_domain_ccc = true;
  domainfile_changed_ccc = true;
  update_display_ccc(0);
  // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
}

// open choose source dialog window
void choose_source_ccc(void)
{
  usb_lun_set_ccc = 0;
  bool use_rebuild_assist_bak = use_rebuild_assist_ccc;
  use_rebuild_assist_ccc = false;
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (memory_failed_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Unable to get buffer physical address in 32 bit range.\nPlease try Starting the Virtual Disk Driver.\n\n Alternative is to try to choose the mode again (switch to different mode and back), or restart the program."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (copy_image_mode_ccc)
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Choose image file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_OPEN,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      fprintf(stdout, "%s\n", filename);
      free(disk_1_ccc);
      disk_1_ccc = malloc(strlen(filename) + 2);
      strcpy(disk_1_ccc, filename);
      g_free(filename);
      current_source_model_ccc[0] = '\0';
      current_source_serial_ccc[0] = '\0';
      update_display_ccc(0);

      if (!connect_source_disk_ccc() && !process_source_ccc() && !check_and_adjust_variables_after_choosing_source_ccc(new_project_ccc))
      {
        source_chosen_ccc = 1;
        if (new_project_ccc)
        {
          initialize_new_log_ccc();
          logfile_changed_ccc = true;
          set_initial_data_from_log_ccc(new_project_ccc);
          logfile_changed_ccc = true;
        }
        clear_domain_ccc();
        strncpy(domain_file_ccc, log_file_ccc, 1016);
        strcat(domain_file_ccc, ".domain");
        printf("%s\n", domain_file_ccc);
        if (access(domain_file_ccc, F_OK) != -1)
        {
          int ret = read_domain_file_ccc(domain_file_ccc);
          if (ret < 0)
          {
            snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
            message_error_ccc(tempmessage_ccc);
            print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
            clear_error_message_ccc();
            clear_domain_ccc();
            // initialize_domainfile_memory_ccc();
            // initialize_domain_log_ccc();
          }
        }
        else
        {
          initialize_domain_log_ccc();
          // domainfile_changed_ccc = true;
        }
      }
      else
      {
        fprintf(stdout, "error selecting source\n");
        clear_source_ccc();
        current_source_model_ccc[0] = '\0';
        current_source_serial_ccc[0] = '\0';
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting source"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      release_devices_ccc();
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    }
    gtk_widget_destroy(dialog);
  }
  else
  {
    if (memory_used_ccc)
    {
      initialize_memory_ccc();
    }
    find_all_devices_ccc();

    choose_source_dialog_window_ccc = gtk_dialog_new_with_buttons(_("Choose Source Drive"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
    // gtk_window_set_title (GTK_WINDOW (choose_source_dialog_window_ccc), "GtkScrolledWindow example");
    gtk_container_set_border_width(GTK_CONTAINER(choose_source_dialog_window_ccc), 0);
    gtk_widget_set_size_request(choose_source_dialog_window_ccc, 600, 400);

    choose_source_scrolled_window_ccc = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(choose_source_scrolled_window_ccc), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(choose_source_scrolled_window_ccc), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(choose_source_dialog_window_ccc)->vbox), choose_source_scrolled_window_ccc, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(choose_source_dialog_window_ccc))), choose_source_scrolled_window_ccc, TRUE, TRUE, 0);

    choose_source_vbox_ccc = gtk_vbox_new(FALSE, 0);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(choose_source_scrolled_window_ccc), choose_source_vbox_ccc);

    GtkWidget *button[MAX_DEVICES];

    if (ahci_mode_ccc)
    {
      int i;
      for (i = 0; i < device_count_ccc; i++)
      {
        char button_label[MAX_BUTTON_LABEL_SIZE] = "";
        if (verbose_ccc & DEBUG6)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s %s %s %llx %d %llx (%lld) %s %s", device_driver_ccc[i], device_bus_ccc[i], device_reference_ccc[i], device_name_ccc[i], hba_address_ccc[i], port_number_ccc[i], port_address_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        else if (verbose_ccc & DEBUG5)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s %llx %d %llx (%lld) %s %s", device_reference_ccc[i], device_name_ccc[i], hba_address_ccc[i], port_number_ccc[i], port_address_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        else
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s (%lld) %s %s", device_reference_ccc[i], device_name_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        button[i] = gtk_button_new_with_label(button_label);
        gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
        g_signal_connect(button[i], "clicked", G_CALLBACK(get_source_from_button_ccc), GINT_TO_POINTER(i));
      }
    }
    else if (direct_mode_ccc)
    {
      int i;
      for (i = 0; i < device_count_ccc; i++)
      {
        char button_label[MAX_BUTTON_LABEL_SIZE] = "";
        if (verbose_ccc & DEBUG6)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s %s %s %llx %llx %llx %d (%lld) %s %s", device_driver_ccc[i], device_bus_ccc[i], device_reference_ccc[i], device_name_ccc[i], reg_address_ccc[i], control_address_ccc[i], bus_address_ccc[i], device_select_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        else if (verbose_ccc & DEBUG5)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s %llx %llx %llx %d (%lld) %s %s", device_reference_ccc[i], device_name_ccc[i], reg_address_ccc[i], control_address_ccc[i], bus_address_ccc[i], device_select_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        else
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s %s (%lld) %s %s", device_reference_ccc[i], device_name_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        }
        button[i] = gtk_button_new_with_label(button_label);
        gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
        g_signal_connect(button[i], "clicked", G_CALLBACK(get_source_from_button_ccc), GINT_TO_POINTER(i));
      }
    }
    else if (usb_mode_ccc)
    {
      int i;
      for (i = 0; i < usb_device_count_ccc; i++)
      {
        char button_label[MAX_BUTTON_LABEL_SIZE] = "";
        if (verbose_ccc & DEBUG6)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%d:%d %04x:%04x %02x %02x %d %s %s %s\n", usb_bus_real_number_ccc[i], usb_device_number_ccc[i], usb_vendor_id_ccc[i], usb_product_id_ccc[i], usb_bulk_in_endpoint_ccc[i], usb_bulk_out_endpoint_ccc[i], usb_mass_storage_ccc[i], usb_vendor_string_ccc[i], usb_product_string_ccc[i], usb_extra_id_string_ccc[i]);
        }
        else if (verbose_ccc & DEBUG5)
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%d:%d %04x:%04x %s %s %s\n", usb_bus_real_number_ccc[i], usb_device_number_ccc[i], usb_vendor_id_ccc[i], usb_product_id_ccc[i], usb_vendor_string_ccc[i], usb_product_string_ccc[i], usb_extra_id_string_ccc[i]);
        }
        else
        {
          snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%d:%d %04x:%04x %s %s\n", usb_bus_real_number_ccc[i], usb_device_number_ccc[i], usb_vendor_id_ccc[i], usb_product_id_ccc[i], usb_vendor_string_ccc[i], usb_product_string_ccc[i]);
        }
        button[i] = gtk_button_new_with_label(button_label);
        gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
        g_signal_connect(button[i], "clicked", G_CALLBACK(get_usb_from_button_ccc), GINT_TO_POINTER(i));
      }
    }
    else
    {
      int i;
      for (i = 0; i < device_count_ccc; i++)
      {
        char button_label[MAX_BUTTON_LABEL_SIZE] = "";
        snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s (%lld) %s %s", drive_list_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
        button[i] = gtk_button_new_with_label(button_label);
        gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
        g_signal_connect(button[i], "clicked", G_CALLBACK(get_source_from_button_ccc), GINT_TO_POINTER(i));
      }
    }

    int i;
    if (usb_mode_ccc)
    {
      for (i = 0; i < usb_device_count_ccc; i++)
      {
        if ((verbose_ccc & DEBUG6) || (verbose_ccc & DEBUG5) || usb_mass_storage_ccc[i])
        {
          gtk_box_pack_start(GTK_BOX(choose_source_vbox_ccc), button[i], FALSE, FALSE, 0);
        }
      }
    }
    else
    {
      for (i = 0; i < device_count_ccc; i++)
      {
        gtk_box_pack_start(GTK_BOX(choose_source_vbox_ccc), button[i], FALSE, FALSE, 0);
      }
    }

    gtk_widget_show_all(choose_source_dialog_window_ccc);
    gint result = gtk_dialog_run(GTK_DIALOG(choose_source_dialog_window_ccc));
    gtk_widget_destroy(choose_source_dialog_window_ccc);

    if (result == GTK_RESPONSE_ACCEPT)
    {
      // fprintf (stdout, "OK\n");
      //  TODO it crashes here on scsi devices - fixed

      // disable the window while it is processing the source
      gtk_widget_set_sensitive(GTK_WIDGET(main_window_ccc), FALSE);

      clear_source_ccc();
      int ret = choose_device_ccc();
      if (ahci_mode_ccc)
      {
        hba_reset_address_ccc = hba_base_address_ccc;
        port_reset_address_ccc = port_base_address_ccc;
      }
      if (ret)
      {
        if (ret == -100)
        {
          clear_source_ccc();
          current_source_model_ccc[0] = '\0';
          current_source_serial_ccc[0] = '\0';
          snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting source"));
          message_error_ccc(tempmessage_ccc);
          print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
          clear_error_message_ccc();
        }
        else if (ret == -200)
        {
          fprintf(stdout, "error selecting source, ret=%d\n", ret);
          clear_source_ccc();
          current_source_model_ccc[0] = '\0';
          current_source_serial_ccc[0] = '\0';
          snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting source"));
          message_error_ccc(tempmessage_ccc);
          print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
          clear_error_message_ccc();
        }
        else
        {
          fprintf(stdout, "error selecting source, ret=%d\n", ret);
          clear_source_ccc();
          current_source_model_ccc[0] = '\0';
          current_source_serial_ccc[0] = '\0';
          snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting source"));
          message_error_ccc(tempmessage_ccc);
          print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
          clear_error_message_ccc();
        }
      }
      else if (!connect_source_disk_ccc() && !process_source_ccc() && !check_and_adjust_variables_after_choosing_source_ccc(new_project_ccc))
      {
        source_chosen_ccc = 1;
        if (new_project_ccc)
        {
          initialize_new_log_ccc();
          logfile_changed_ccc = true;
          set_initial_data_from_log_ccc(new_project_ccc);
          logfile_changed_ccc = true;
        }
        clear_domain_ccc();
        strncpy(domain_file_ccc, log_file_ccc, 1016);
        strcat(domain_file_ccc, ".domain");
        printf("%s\n", domain_file_ccc);
        if (access(domain_file_ccc, F_OK) != -1)
        {
          int ret = read_domain_file_ccc(domain_file_ccc);
          if (ret < 0)
          {
            snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
            message_error_ccc(tempmessage_ccc);
            print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
            clear_error_message_ccc();
            clear_domain_ccc();
            // initialize_domainfile_memory_ccc();
            // initialize_domain_log_ccc();
          }
        }
        else
        {
          initialize_domain_log_ccc();
          // domainfile_changed_ccc = true;
        }
      }
      else
      {
        fprintf(stdout, "error selecting source\n");
        clear_source_ccc();
        current_source_model_ccc[0] = '\0';
        current_source_serial_ccc[0] = '\0';
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting source"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      release_devices_ccc();
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);

      // re-enable the window
      gtk_widget_set_sensitive(GTK_WIDGET(main_window_ccc), TRUE);
    }
  }
  use_rebuild_assist_ccc = use_rebuild_assist_bak;
}

void get_source_from_button_ccc(GtkWidget *w, gpointer data)
{
  new_source_ccc = GPOINTER_TO_INT(data);
  g_print("selection=%d  \n", new_source_ccc);
}

void choose_destination_drive_ccc(void)
{
  destination_is_generic_ccc = false;
  choose_destination_ccc();
}

void choose_destination_block_ccc(void)
{
  destination_is_generic_ccc = true;
  choose_destination_ccc();
}

// open choose destination dialog window
void choose_destination_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    bool direct_mode_bak = direct_mode_ccc;
    bool ahci_mode_bak = ahci_mode_ccc;
    bool ata_passthrough_bak = ata_passthrough_ccc;
    bool scsi_passthrough_bak = scsi_passthrough_ccc;
    bool generic_mode_ccc_bak = generic_mode_ccc;
    bool usb_mode_bak = usb_mode_ccc;

    direct_mode_ccc = false;
    ahci_mode_ccc = false;
    ata_passthrough_ccc = false;
    scsi_passthrough_ccc = !destination_is_generic_ccc;
    generic_mode_ccc = destination_is_generic_ccc;
    usb_mode_ccc = false;
    if (memory_used_ccc)
    {
      initialize_memory_ccc();
    }
    find_all_devices_ccc();
    direct_mode_ccc = direct_mode_bak;
    ahci_mode_ccc = ahci_mode_bak;
    ata_passthrough_ccc = ata_passthrough_bak;
    scsi_passthrough_ccc = scsi_passthrough_bak;
    generic_mode_ccc = generic_mode_ccc_bak;
    usb_mode_ccc = usb_mode_bak;

    choose_destination_dialog_window_ccc = gtk_dialog_new_with_buttons(_("Destination (All data will be overwritten!)"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
    // gtk_window_set_title (GTK_WINDOW (choose_source_dialog_window_ccc), "GtkScrolledWindow example");
    gtk_container_set_border_width(GTK_CONTAINER(choose_destination_dialog_window_ccc), 0);
    gtk_widget_set_size_request(choose_destination_dialog_window_ccc, 600, 400);

    choose_destination_scrolled_window_ccc = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_set_border_width(GTK_CONTAINER(choose_destination_scrolled_window_ccc), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(choose_destination_scrolled_window_ccc), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(choose_destination_dialog_window_ccc)->vbox), choose_destination_scrolled_window_ccc, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(choose_destination_dialog_window_ccc))), choose_destination_scrolled_window_ccc, TRUE, TRUE, 0);

    choose_destination_vbox_ccc = gtk_vbox_new(FALSE, 0);
    gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(choose_destination_scrolled_window_ccc), choose_destination_vbox_ccc);

    GtkWidget *button[MAX_DEVICES];

    int i;
    for (i = 0; i < device_count_ccc; i++)
    {
      char button_label[MAX_BUTTON_LABEL_SIZE] = "";
      snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%s (%lld) %s %s", drive_list_ccc[i], drive_size_ccc[i], model_ccc[i], serial_ccc[i]);
      button[i] = gtk_button_new_with_label(button_label);
      gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
      g_signal_connect(button[i], "clicked", G_CALLBACK(get_destination_from_button_ccc), GINT_TO_POINTER(i));
    }

    for (i = 0; i < device_count_ccc; i++)
    {
      gtk_box_pack_start(GTK_BOX(choose_destination_vbox_ccc), button[i], FALSE, FALSE, 0);
    }

    gtk_widget_show_all(choose_destination_dialog_window_ccc);
    gint result = gtk_dialog_run(GTK_DIALOG(choose_destination_dialog_window_ccc));
    gtk_widget_destroy(choose_destination_dialog_window_ccc);

    if (result == GTK_RESPONSE_ACCEPT)
    {
      // fprintf (stdout, "OK\n");
      generic_mode_ccc = destination_is_generic_ccc;
      int ret = choose_target_ccc();
      generic_mode_ccc = generic_mode_ccc_bak;
      if (ret)
      {
        fprintf(stdout, "error selecting destination, ret=%d\n", ret);
        clear_destination_ccc();
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error selecting destination"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
      }
      else
      {
        destination_chosen_ccc = 1;
        destination_size_valid_ccc = 1;
        logfile_changed_ccc = true;

        if (driver_only_ccc)
        {
          clear_domain_ccc();
          strncpy(domain_file_ccc, log_file_ccc, 1016);
          strcat(domain_file_ccc, ".domain");
          printf("%s\n", domain_file_ccc);
          if (access(domain_file_ccc, F_OK) != -1)
          {
            int ret = read_domain_file_ccc(domain_file_ccc);
            if (ret < 0)
            {
              snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
              message_error_ccc(tempmessage_ccc);
              print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
              clear_error_message_ccc();
              clear_domain_ccc();
              // initialize_domainfile_memory_ccc();
              // initialize_domain_log_ccc();
            }
          }
          else
          {
            initialize_domain_log_ccc();
            domainfile_changed_ccc = true;
          }
        }
      }
      update_display_ccc(0);
      // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    }
  }
}

void get_destination_from_button_ccc(GtkWidget *w, gpointer data)
{
  new_destination_ccc = GPOINTER_TO_INT(data);
  g_print("selection=%d  \n", new_destination_ccc);
}

void choose_image_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    GtkWidget *dialog;
    dialog = gtk_file_chooser_dialog_new(_("Choose image file"),
                                         GTK_WINDOW(main_window_ccc),
                                         GTK_FILE_CHOOSER_ACTION_SAVE,
                                         GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                         GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
                                         NULL);
    // gtk_file_chooser_set_do_overwrite_confirmation (GTK_FILE_CHOOSER (dialog), TRUE);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
      int confirmed = 1;
      char *filename;
      filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
      if (access(filename, F_OK) == 0)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "   %s   \n%s", filename, _("The image file currently exists.\nThis will continue the recovery using this image file."));
        if (!open_confirmation_dialog_ccc(tempmessage_ccc))
        {
          confirmed = 0;
        }
      }
      if (confirmed)
      {
        fprintf(stdout, "%s\n", filename);
        free(disk_2_ccc);
        disk_2_ccc = malloc(strlen(filename) + 2);
        strcpy(disk_2_ccc, filename);
        destination_chosen_ccc = 1;
        destination_size_valid_ccc = 0;
        current_destination_model_ccc[0] = '\0';
        current_destination_serial_ccc[0] = '\0';
        logfile_changed_ccc = true;

        if (driver_only_ccc)
        {
          clear_domain_ccc();
          strncpy(domain_file_ccc, log_file_ccc, 1016);
          strcat(domain_file_ccc, ".domain");
          printf("%s\n", domain_file_ccc);
          if (access(domain_file_ccc, F_OK) != -1)
          {
            int ret = read_domain_file_ccc(domain_file_ccc);
            if (ret < 0)
            {
              snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error processing log file!\nThe log file was not loaded.\n"));
              message_error_ccc(tempmessage_ccc);
              print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
              clear_error_message_ccc();
              clear_domain_ccc();
              // initialize_domainfile_memory_ccc();
              // initialize_domain_log_ccc();
            }
          }
          else
          {
            initialize_domain_log_ccc();
            domainfile_changed_ccc = true;
          }
        }

        update_display_ccc(0);
        // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
      }
      g_free(filename);
      gtk_widget_destroy(dialog);
    }
  }
}

void choose_null_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must disconnect first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    fprintf(stdout, "/dev/null\n");
    free(disk_2_ccc);
    disk_2_ccc = malloc(16);
    strcpy(disk_2_ccc, "/dev/null");
    strcpy(current_destination_model_ccc, _("NULL (No destination)"));
    strcpy(current_destination_serial_ccc, "");
    logfile_changed_ccc = true;
    update_display_ccc(0);
    // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);
    destination_chosen_ccc = 1;
    destination_size_valid_ccc = 0;
  }
}

void connect_devices_ccc(void)
{
  int relaycheck = 1;
  if ((activate_primary_relay_on_error_ccc || power_cycle_primary_relay_ccc) && !(fill_mode_ccc || driver_only_ccc) && !usbr1_chosen_ccc)
  {
    relaycheck = 0;
  }
  if (memory_failed_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Unable to get buffer physical address in 32 bit range.\nPlease try Starting the Virtual Disk Driver.\n\n Alternative is to try to choose the mode again (switch to different mode and back), or restart the program."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else if (relaycheck && project_chosen_ccc && destination_chosen_ccc && (fill_mode_ccc || driver_only_ccc))
  {
    check_log_size_ccc = 0;
    // check log and if only same status then repair automatically
    int ret = check_log_ccc();
    int ret2 = 0;
    if (ret == 0x10)
    {
      clear_error_message_ccc();
      ret2 = check_and_repair_log_ccc();
      ret = check_log_ccc();
    }
    if (new_project_ccc && !fill_mode_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("No source chosen\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      set_disconnected_ccc();
    }
    else if (ret || ret2)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      set_disconnected_ccc();
    }
    else if (driver_only_ccc && !driver_installed_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The virtual disk device driver is not running"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      set_disconnected_ccc();
    }
    else
    {
      if (open_target_destination_ccc())
      {
        release_devices_ccc();
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Unable to connect devices"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
        set_disconnected_ccc();
      }
      else
      {
        // strcpy (tempmessage_ccc, _("Devices now connected"));
        // message_error_ccc(tempmessage_ccc);
        // print_gui_error_message_ccc(error_message_ccc, _("Success!"), 0);
        // clear_error_message_ccc();
        check_and_adjust_variables_after_connection_ccc();
        set_connected_ccc();
      }
    }
  }
  else if (relaycheck && project_chosen_ccc && source_chosen_ccc && destination_chosen_ccc)
  {
    check_log_size_ccc = 1;
    // check log and if only same status then repair automatically
    int ret = check_log_ccc();
    int ret2 = 0;
    if (ret == 0x10)
    {
      clear_error_message_ccc();
      ret2 = check_and_repair_log_ccc();
      ret = check_log_ccc();
    }
    if (check_same_device_ccc())
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Source and Destination cannot be the same device"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      set_disconnected_ccc();
    }
    else if (ret || ret2)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      set_disconnected_ccc();
    }
    else
    {
      if (connect_source_disk_ccc() || open_target_destination_ccc())
      {
        release_devices_ccc();
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Unable to connect devices"));
        message_error_ccc(tempmessage_ccc);
        print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
        clear_error_message_ccc();
        set_disconnected_ccc();
      }
      else
      {
        // strcpy (tempmessage_ccc, _("Devices now connected"));
        // message_error_ccc(tempmessage_ccc);
        // print_gui_error_message_ccc(error_message_ccc, _("Success!"), 0);
        // clear_error_message_ccc();
        if (!enable_scsi_write_ccc && destination_size_valid_ccc && source_total_size_ccc > target_total_size_ccc)
        {
          fprintf(stdout, "Warning! Destination is smaller than souce.\n");
          fprintf(stdout, "Source size= %lld\n", source_total_size_ccc);
          fprintf(stdout, "Target size= %lld\n", target_total_size_ccc);
          snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Warning! The destination is smaller than the source.\nSome data may not be copied."));
          message_error_ccc(tempmessage_ccc);
          print_gui_error_message_ccc(error_message_ccc, _("Warning"), 1);
          clear_error_message_ccc();
        }
        check_and_adjust_variables_after_connection_ccc();
        set_connected_ccc();
        new_project_ccc = 0;
      }
    }
  }
  else
  {
    if (!project_chosen_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("No project chosen\n"));
      message_error_ccc(tempmessage_ccc);
    }
    if (!source_chosen_ccc && !(fill_mode_ccc || driver_only_ccc))
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("No source chosen\n"));
      message_error_ccc(tempmessage_ccc);
    }
    if (!destination_chosen_ccc)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("No destination chosen\n"));
      message_error_ccc(tempmessage_ccc);
    }
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project, source, and destination before connecting."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    if (!relaycheck)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
  }
  ata_status_ccc = 0;
  ata_error_ccc = 0;
  update_display_ccc(0);
}

void start_display_status_update_timer_ccc(void)
{
  // g_print ("start=%d timer=%d\n", display_status_timer_ccc, display_status_timer_running_ccc);    //debug
  if (direct_mode_ccc && !display_status_timer_running_ccc)
  {
    display_status_timer_ccc = gdk_threads_add_timeout(500, display_status_update_action_ccc, NULL);
    display_status_timer_running_ccc = 1;
  }
}

void stop_display_status_update_timer_ccc(void)
{
  if (display_status_timer_running_ccc)
  {
    // gtk_timeout_remove (display_status_timer_ccc);
    display_status_timer_running_ccc = 0;
  }
}

gint display_status_update_action_ccc(gpointer data)
{
  if (fill_mode_ccc || !connected_ccc || running_clone_ccc || !display_status_timer_running_ccc)
  {
    display_status_timer_running_ccc = 0;
    return 0;
  }
  // g_print ("timer\n");    //debug
  refresh_status_ccc(current_disk_ccc);
  update_gui_status_buttons_ccc();
  data = data;
  return 1;
}

void disconnect_devices_ccc(void)
{
  release_devices_ccc();
  connected_ccc = 0;
  // strcpy (tempmessage_ccc, _("Devices now disconnected"));
  // message_error_ccc(tempmessage_ccc);
  // print_gui_error_message_ccc(error_message_ccc, _("Success!"), 0);
  // clear_error_message_ccc();
  set_disconnected_ccc();
  ata_status_ccc = 0;
  ata_error_ccc = 0;
  update_display_ccc(0);
}

void set_connected_ccc(void)
{
  if (driver_mode_ccc && (strcmp(disk_2_ccc, "/dev/null") == 0))
  {
    clear_error_message_ccc();
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Warning! Using driver mode with destination of null will clear the current progress log.\nOnce you click on Start, the log will be cleared.\nIf you wish to keep the current log, disconnect and make a copy."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Warning"), 0);
    clear_error_message_ccc();
  }
  connected_ccc = 1;
  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(modemi_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(drivesmi_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(primaryrelaymi_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(chooseprimaryrelaymi_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), driver_only_ccc ? FALSE : TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(activate_primary_relay_button_main_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(deactivate_primary_relay_button_main_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), TRUE);
  if (driver_installed_ccc)
  {
    set_driver_mode_button_status_ccc(TRUE);
  }
  start_display_status_update_timer_ccc();
  stop_signal_ccc = false;
  process_dma_mode_ccc();
}

void set_disconnected_ccc(void)
{
  connected_ccc = 0;
  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(stop_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(modemi_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(drivesmi_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(primaryrelaymi_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(chooseprimaryrelaymi_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(activate_primary_relay_button_main_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(deactivate_primary_relay_button_main_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), FALSE);
  set_driver_mode_button_status_ccc(FALSE);
  stop_display_status_update_timer_ccc();
}

void clear_source_ccc(void)
{
  source_chosen_ccc = 0;
  disk_1_ccc = NULL;
  current_source_model_ccc[0] = '\0';
  current_source_serial_ccc[0] = '\0';
  source_total_size_ccc = 0;
}

void clear_destination_ccc(void)
{
  destination_chosen_ccc = 0;
  disk_2_ccc = NULL;
  current_destination_model_ccc[0] = '\0';
  current_destination_serial_ccc[0] = '\0';
}

void update_gui_display_ccc(void)
{
  gtk_label_set_text(GTK_LABEL(main_label), "");
  // gtk_label_set_text(GTK_LABEL(main_label), display_message_ccc);

  gtk_label_set_text(GTK_LABEL(data_project_ccc), display_output_ccc.logfile);
  gtk_label_set_text(GTK_LABEL(data_domain_ccc), display_output_ccc.domainfile);
  gtk_label_set_text(GTK_LABEL(data_source_ccc), display_output_ccc.source);
  gtk_label_set_text(GTK_LABEL(data_destination_ccc), display_output_ccc.destination);
  gtk_label_set_text(GTK_LABEL(data_totallba_ccc), display_output_ccc.totallba);
  gtk_label_set_text(GTK_LABEL(data_lbatoread_ccc), display_output_ccc.lbatoread);
  gtk_label_set_text(GTK_LABEL(data_domainsize_ccc), display_output_ccc.domainsize);
  gtk_label_set_text(GTK_LABEL(data_runtime_ccc), display_output_ccc.runtime);
  gtk_label_set_text(GTK_LABEL(data_remainingtime_ccc), display_output_ccc.remainingtime);
  gtk_label_set_text(GTK_LABEL(data_currentposition_ccc), display_output_ccc.currentposition);
  gtk_label_set_text(GTK_LABEL(data_currentstatus_ccc), display_output_ccc.currentstatus);
  gtk_label_set_text(GTK_LABEL(data_currentrate_ccc), display_output_ccc.currentrate);
  gtk_label_set_text(GTK_LABEL(data_recentrate_ccc), display_output_ccc.recentrate);
  gtk_label_set_text(GTK_LABEL(data_totalrate_ccc), display_output_ccc.totalrate);
  gtk_label_set_text(GTK_LABEL(data_skipsize_ccc), display_output_ccc.skipsize);
  gtk_label_set_text(GTK_LABEL(data_slowskips_ccc), display_output_ccc.slowskips);
  gtk_label_set_text(GTK_LABEL(data_skips_ccc), display_output_ccc.skips);
  gtk_label_set_text(GTK_LABEL(data_skipruns_ccc), display_output_ccc.skipruns);
  gtk_label_set_text(GTK_LABEL(data_skipresets_ccc), display_output_ccc.skipresets);
  gtk_label_set_text(GTK_LABEL(data_runsize_ccc), display_output_ccc.runsize);
  gtk_label_set_text(GTK_LABEL(data_finished_ccc), display_output_ccc.finished);
  gtk_label_set_text(GTK_LABEL(data_nontried_ccc), display_output_ccc.nontried);
  gtk_label_set_text(GTK_LABEL(data_nontrimmed_ccc), display_output_ccc.nontrimmed);
  gtk_label_set_text(GTK_LABEL(data_nondivided_ccc), display_output_ccc.nondivided);
  gtk_label_set_text(GTK_LABEL(data_nonscraped_ccc), display_output_ccc.nonscraped);
  gtk_label_set_text(GTK_LABEL(data_bad_ccc), display_output_ccc.bad);
  gtk_label_set_text(GTK_LABEL(data_datapreview_ccc), display_output_ccc.datapreview);
  gtk_label_set_text(GTK_LABEL(data_longestreadtime_ccc), display_output_ccc.longestreadtime);
  gtk_label_set_text(GTK_LABEL(data_filled_ccc), display_output_ccc.totalfilled);
  gtk_label_set_text(GTK_LABEL(data_retried_ccc), display_output_ccc.retried);
  gtk_label_set_text(GTK_LABEL(data_retrypasses_ccc), display_output_ccc.retrypasses);
  // gtk_label_set_text(GTK_LABEL(), display_output_ccc.);
  // gtk_label_set_text(GTK_LABEL(), display_output_ccc.);
  // gtk_label_set_text(GTK_LABEL(), display_output_ccc.);
  // gtk_label_set_text(GTK_LABEL(), display_output_ccc.);

  update_status_buttons_ccc();
  run_gtk_gui_update_ccc();
}

void update_gui_status_buttons_ccc(void)
{
  update_status_buttons_ccc();
  run_gtk_gui_update_ccc();
}

void run_gtk_gui_update_ccc(void)
{
  while (gtk_events_pending())
  {
    gtk_main_iteration();
  }
}

void set_stop_signal_ccc(void)
{
  stop_signal_ccc = true;
}

void set_clone_mode_ccc(void)
{
  if (driver_mode_ccc)
  {
    do_domain_ccc = true;
  }
  driver_mode_ccc = 0;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Clone"));
  update_display_ccc(0);
}

void set_driver_mode1_ccc(void)
{
  do_domain_ccc = false;
  check_driver_null_condition_ccc();
  driver_mode_ccc = 1;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Mode 1"));
  update_display_ccc(0);
}

void set_driver_mode2_ccc(void)
{
  do_domain_ccc = false;
  check_driver_null_condition_ccc();
  driver_mode_ccc = 2;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Mode 2"));
  update_display_ccc(0);
}

void set_driver_mode3_ccc(void)
{
  do_domain_ccc = false;
  check_driver_null_condition_ccc();
  driver_mode_ccc = 3;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Mode 3"));
  update_display_ccc(0);
}

void set_driver_mode4_ccc(void)
{
  do_domain_ccc = false;
  check_driver_null_condition_ccc();
  driver_mode_ccc = 4;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Mode 4"));
  update_display_ccc(0);
}

void set_driver_mode5_ccc(void)
{
  do_domain_ccc = false;
  check_driver_null_condition_ccc();
  driver_mode_ccc = 5;
  gtk_label_set_text(GTK_LABEL(data_drivermode_ccc), _("Mode 5"));
  update_display_ccc(0);
}

void check_driver_null_condition_ccc(void)
{
  // only check if coming from clone mode and destination string is not NULL
  if (disk_2_ccc != NULL && driver_mode_ccc == 0 && (strcmp(disk_2_ccc, "/dev/null") == 0))
  {
    clear_error_message_ccc();
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Warning! Using driver mode with destination of null will clear the current progress log.\nOnce you click on Start, the log will be cleared.\nIf you wish to keep the current log, disconnect and make a copy."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Warning"), 0);
    clear_error_message_ccc();
  }
}

void set_driver_mode_button_status_ccc(bool active)
{
  if (driver_installed_ccc)
  {
    if (driver_only_ccc)
    {
      set_driver_mode4_ccc();
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode4_button_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(agressive_driver_checkbutton_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode1_button_ccc), FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode2_button_ccc), FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode3_button_ccc), FALSE);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode5_button_ccc), FALSE);
    }
    else
    {
      gtk_widget_set_sensitive(GTK_WIDGET(agressive_driver_checkbutton_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode1_button_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode2_button_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode3_button_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode4_button_ccc), active);
      gtk_widget_set_sensitive(GTK_WIDGET(driver_mode5_button_ccc), active);
    }
  }
  else
  {
    gtk_widget_set_sensitive(GTK_WIDGET(driver_mode4_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(agressive_driver_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(driver_mode1_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(driver_mode2_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(driver_mode3_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(driver_mode5_button_ccc), FALSE);
  }
}

void start_cloning_ccc(void)
{
  int ret = 0;
  stop_display_status_update_timer_ccc();
  stop_signal_ccc = false;
  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(stop_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(topmenubar_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), FALSE);
  if (driver_mode_ccc)
  {
    set_driver_mode_button_status_ccc(TRUE);
  }
  else
  {
    set_driver_mode_button_status_ccc(FALSE);
  }

  running_clone_ccc = 1;
  memory_used_ccc = 1;
  if (driver_mode_ccc == 0)
  {
    ret = begin_cloning_ccc();
  }
  else
  {
    gtk_label_set_text(GTK_LABEL(label_filled_ccc), _("Last read size"));
    ret = begin_driver_ccc();
    gtk_label_set_text(GTK_LABEL(label_filled_ccc), _("Filled"));
  }
  running_clone_ccc = 0;
  update_logfile_ccc(0);
  update_domainfile_ccc(0);

  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(stop_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(topmenubar_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), driver_only_ccc ? FALSE : TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), TRUE);
  set_driver_mode_button_status_ccc(TRUE);

  if (ret && ret != STOP_SIGNAL_RETURN_CODE)
  {
    disconnect_devices_ccc();
  }
  start_display_status_update_timer_ccc();
}

void analyze_quick_ccc(void)
{
  enable_extended_analyze_ccc = false;
  start_analyzing_ccc();
}

void analyze_long_ccc(void)
{
  enable_extended_analyze_ccc = true;
  start_analyzing_ccc();
}

void start_analyzing_ccc(void)
{
  int ret = 0;
  stop_display_status_update_timer_ccc();
  stop_signal_ccc = false;
  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(stop_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(topmenubar_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), FALSE);

  set_driver_mode_button_status_ccc(FALSE);

  memory_used_ccc = 1;

  int extended = 0;
  int sections = MAXANALYZESECTIONS / 4;
  if (enable_extended_analyze_ccc)
  {
    extended = 1;
    sections = MAXANALYZESECTIONS;
  }

  memset(analyze_read_attempts_ccc, 0, sizeof(analyze_read_attempts_ccc));
  memset(analyze_good_reads_ccc, 0, sizeof(analyze_good_reads_ccc));
  memset(analyze_bad_reads_ccc, 0, sizeof(analyze_bad_reads_ccc));
  memset(analyze_slow_reads_ccc, 0, sizeof(analyze_slow_reads_ccc));
  memset(analyze_timeouts_ccc, 0, sizeof(analyze_timeouts_ccc));
  memset(analyze_read_time_ccc, 0, sizeof(analyze_read_time_ccc));
  // memset (analyze_low_time_ccc, 0x7f, sizeof(analyze_low_time_ccc));
  memset(analyze_high_time_ccc, 0, sizeof(analyze_high_time_ccc));
  memset(analyze_text_ccc, 0, sizeof(analyze_text_ccc));
  memset(analyze_slow_position_ccc, 0, sizeof(analyze_slow_position_ccc));
  memset(analyze_slow_size_ccc, 0, sizeof(analyze_slow_size_ccc));
  // memset (analyze_slow_low_ccc, 0x7f, sizeof(analyze_slow_low_ccc));
  memset(analyze_slow_high_ccc, 0, sizeof(analyze_slow_high_ccc));
  analyze_slow_total_reads_ccc = 0;
  int i;
  for (i = 0; i < MAXANALYZESECTIONS; i++)
  {
    analyze_low_time_ccc[i] = 999999999999;
    analyze_slow_low_ccc[i] = 999999999999;
  }
  running_analyze_ccc = 1;
  gtk_label_set_text(GTK_LABEL(label_filled_ccc), _("Total, Good, Bad, Slow"));
  ret = analyze_drive_ccc(sections, extended);
  gtk_label_set_text(GTK_LABEL(label_filled_ccc), _("Filled"));
  running_analyze_ccc = 0;

  long long average_read_time[MAXANALYZESECTIONS];
  memset(average_read_time, 0, sizeof(average_read_time));
  for (i = 0; i < sections; i++)
  {
    // prevent divid by 0 error
    if (analyze_read_attempts_ccc[i] != 0)
    {
      average_read_time[i] = analyze_read_time_ccc[i] / analyze_read_attempts_ccc[i];
    }
  }

  long long total_average_read_time = 0;
  for (i = 0; i < sections; i++)
  {
    total_average_read_time = total_average_read_time + average_read_time[i];
  }
  total_average_read_time = total_average_read_time / sections;

  long long total_low_time = analyze_low_time_ccc[0];
  for (i = 0; i < sections; i++)
  {
    if (analyze_low_time_ccc[i] < total_low_time)
    {
      total_low_time = analyze_low_time_ccc[i];
    }
  }

  long long total_high_time = analyze_high_time_ccc[0];
  for (i = 0; i < sections; i++)
  {
    if (analyze_high_time_ccc[i] > total_high_time)
    {
      total_high_time = analyze_high_time_ccc[i];
    }
  }

  int total_read_attempts = 0;
  for (i = 0; i < sections; i++)
  {
    total_read_attempts = total_read_attempts + analyze_read_attempts_ccc[i];
  }

  int total_good_reads = 0;
  for (i = 0; i < sections; i++)
  {
    total_good_reads = total_good_reads + analyze_good_reads_ccc[i];
  }

  int total_bad_reads = 0;
  for (i = 0; i < sections; i++)
  {
    total_bad_reads = total_bad_reads + analyze_bad_reads_ccc[i];
  }

  int total_slow_reads = 0;
  for (i = 0; i < sections; i++)
  {
    total_slow_reads = total_slow_reads + analyze_slow_reads_ccc[i];
  }

  int total_timeouts = 0;
  for (i = 0; i < sections; i++)
  {
    total_timeouts = total_timeouts + analyze_timeouts_ccc[i];
  }

  float good_percent;
  float bad_percent;
  float slow_percent;
  good_percent = 100.0f * total_good_reads / total_read_attempts;
  bad_percent = 100.0f * total_bad_reads / total_read_attempts;
  slow_percent = 100.0f * total_slow_reads / total_read_attempts;
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Good"), good_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Bad"), bad_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Slow"), slow_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "#\n");
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  float slow_issue_percent;
  if (slow_percent > 50.0f)
  {
    slow_issue_percent = slow_percent;
  }
  else
  {
    slow_issue_percent = slow_percent / 2.0f;
  }
  float slow_variance_percent = 0.0f;
  if (1)
  {
    int slowsections = MAXANALYZESLOW / 4;
    if (extended)
    {
      slowsections = MAXANALYZESLOW;
    }
    int slow_variance_count = 0;
    for (i = 0; i < slowsections; i++)
    {
      if (analyze_slow_high_ccc[i] - analyze_slow_low_ccc[i] > skip_timeout_copy_ccc)
      {
        slow_variance_count++;
      }
    }
    slow_variance_percent = 100.0f * slow_variance_count / slowsections;
  }
  slow_issue_percent = slow_issue_percent + slow_variance_percent;
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Slow Responding Firmware Issue"), slow_issue_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  int consecutive_no_read_sections = 0;
  int highest_no_read_sections = 0;
  long long highest_read_time_sections = 0;
  for (i = 0; i < sections; i++)
  {
    if (analyze_read_attempts_ccc[i] > 0 && analyze_good_reads_ccc[i] == 0)
    {
      consecutive_no_read_sections++;
      if (highest_no_read_sections < consecutive_no_read_sections)
      {
        highest_no_read_sections = consecutive_no_read_sections;
      }
      if (highest_read_time_sections < analyze_high_time_ccc[i])
      {
        highest_read_time_sections = analyze_high_time_ccc[i];
      }
    }
    else
    {
      consecutive_no_read_sections = 0;
    }
  }
  float partial_access_percent = 100.0f * consecutive_no_read_sections / sections;
  if (consecutive_no_read_sections > 0 && highest_read_time_sections < skip_timeout_copy_ccc)
  {
    partial_access_percent = partial_access_percent * 2.0f;
  }
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Partial Access Issue"), partial_access_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  int bad_sections = 0;
  for (i = 0; i < sections; i++)
  {
    if (analyze_bad_reads_ccc[i] > 0)
    {
      bad_sections++;
    }
    else if (analyze_slow_reads_ccc[i] > 0 && slow_issue_percent < 50.0f)
    {
      bad_sections++;
    }
  }
  float bad_head_percent = 100.0f * bad_sections / sections;
  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s = %f%%\n", _("Bad Or Weak Head"), bad_head_percent);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "#\n");
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  if (1)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# (%d) %s", analyze_slow_total_reads_ccc, _("Variance read times low/high:"));
    strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
    int slowsections = MAXANALYZESLOW / 4;
    if (extended)
    {
      slowsections = MAXANALYZESLOW;
    }
    for (i = 0; i < slowsections; i++)
    {
      if ((i % 8) == 0)
      {
        snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "\n#     ");
        strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
      }
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%lld/%lld  ", analyze_slow_low_ccc[i] / 1000, analyze_slow_high_ccc[i] / 1000);
      strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
    }
    strncat(analyze_text_ccc, "\n", MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
  }

  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "#\n");
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "# %s   %s %d    %s %d    %s %d (%d)    %s %d    %s %lld    %s %lld    %s %lld", _("Zones"), _("Total"), total_read_attempts, _("Good"), total_good_reads, _("Bad"), total_bad_reads, total_timeouts, _("Slow"), total_slow_reads, _("Low"), total_low_time / 1000, _("High"), total_high_time / 1000, _("Average"), total_average_read_time / 1000);
  strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);

  for (i = 0; i < sections; i++)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "\n# %s %d    %s %d    %s %d    %s %d (%d)    %s %d    %s %lld    %s %lld    %s %lld", _("Zone"), i, _("Total"), analyze_read_attempts_ccc[i], _("Good"), analyze_good_reads_ccc[i], _("Bad"), analyze_bad_reads_ccc[i], analyze_timeouts_ccc[i], _("Slow"), analyze_slow_reads_ccc[i], _("Low"), analyze_low_time_ccc[i] / 1000, _("High"), analyze_high_time_ccc[i] / 1000, _("Average"), average_read_time[i] / 1000);
    strncat(analyze_text_ccc, tempmessage_ccc, MAX_ANALYZE_TEXT_LENGTH - strlen(analyze_text_ccc) - 1);
  }
  fprintf(stdout, "%s", analyze_text_ccc);

  display_analyze_results_ccc();

  update_logfile_ccc(0);

  gtk_widget_set_sensitive(GTK_WIDGET(connect_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(disconnect_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(start_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(stop_button_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(topmenubar_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(clone_mode_button_ccc), driver_only_ccc ? FALSE : TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(smart_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_button_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(analyze_long_button_ccc), TRUE);
  if (driver_installed_ccc)
  {
    set_driver_mode_button_status_ccc(TRUE);
  }

  if (ret && ret != STOP_SIGNAL_RETURN_CODE)
  {
    disconnect_devices_ccc();
  }
  start_display_status_update_timer_ccc();
  logfile_changed_ccc = true;
}

void display_analyze_results_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "analyze_results_dialog"));
  GtkWidget *analyze_results_data_label = GTK_WIDGET(gtk_builder_get_object(builder, "analyze_results_data_label"));
  // GtkWidget *analyze_results_box_label = GTK_WIDGET (gtk_builder_get_object (builder, "analyze_results_box_label"));
  //  = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  //  = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(analyze_results_data_label), analyze_text_ccc);

  gtk_window_set_title(GTK_WINDOW(dialog), _("Results"));
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void get_smart_data_ccc(void)
{
  stop_signal_ccc = false;
  memset(smart_data_text_ccc, 0, sizeof(smart_data_text_ccc));
  int ret = extract_smart_data_ccc();
  if (ret == 0)
  {
    fprintf(stdout, "%s", smart_data_text_ccc);
    display_smart_data_ccc();
  }
  logfile_changed_ccc = true;
}

void display_smart_data_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "smart_results_dialog"));
  GtkWidget *smart_results_data_label = GTK_WIDGET(gtk_builder_get_object(builder, "smart_results_data_label"));
  // GtkWidget *smart_results_box_label = GTK_WIDGET (gtk_builder_get_object (builder, "smart_results_box_label"));
  //  = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  //  = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(smart_results_data_label), smart_data_text_ccc);

  gtk_window_set_title(GTK_WINDOW(dialog), _("Results"));
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void display_identify_data_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "identify_results_dialog"));
  GtkWidget *smart_results_data_label = GTK_WIDGET(gtk_builder_get_object(builder, "identify_results_data_label"));
  // GtkWidget *smart_results_box_label = GTK_WIDGET (gtk_builder_get_object (builder, "smart_results_box_label"));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(smart_results_data_label), identify_device_raw_text_ccc);

  gtk_window_set_title(GTK_WINDOW(dialog), _("Results"));
  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

void quit_and_close_ccc(void)
{
  gtk_main_quit();
  quit_and_exit_ccc();
}

void open_clone_settings_dialog_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "clone_settings_dialog"));
  phase_control_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase_control_label"));
  phase1_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase1_checkbutton"));
  phase2_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase2_checkbutton"));
  phase3_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase3_checkbutton"));
  phase4_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase4_checkbutton"));
  divide_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "divide_checkbutton"));
  divide2_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "divide2_checkbutton"));
  trim_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "trim_checkbutton"));
  scrape_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "scrape_checkbutton"));
  markbad_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "markbad_checkbutton"));
  readbad_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "readbad_checkbutton"));
  rebuild_assist_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "rebuild_assist_checkbutton"));
  reverse_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "reverse_checkbutton"));
  skipfast_check_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "skipfast_checkbutton"));
  retries_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "retries_button_label"));
  retries_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "retries_spinbutton"));
  clustersize_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "clustersize_button_label"));
  clustersize_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "clustersize_spinbutton"));
  inputoffset_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "inputoffset_button_label"));
  inputoffset_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "inputoffset_spinbutton"));
  size_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "size_button_label"));
  size_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "size_spinbutton"));
  blocksize_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "blocksize_button_label"));
  blocksize_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "blocksize_spinbutton"));
  skipsize_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "skipsize_button_label"));
  skipsize_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "skipsize_spinbutton"));
  maxskipsize_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "maxskipsize_button_label"));
  maxskipsize_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "maxskipsize_spinbutton"));
  skipthreshold_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "skipthreshold_button_label"));
  skipthreshold_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "skipthreshold_spinbutton"));
  rateskip_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "rateskip_button_label"));
  rateskip_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "rateskip_spinbutton"));
  exitonslow_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "exitonslow_button_label"));
  exitonslow_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "exitonslow_spinbutton"));
  exitonslowtime_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "exitonslowtime_button_label"));
  exitonslowtime_spin_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "exitonslowtime_spinbutton"));
  sectorsize_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "sectorsize_button_label"));
  sectorsize_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "sectorsize_spinbutton"));
  alignment_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "alignment_button_label"));
  alignment_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "alignment_spinbutton"));
  maxreadrate_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "maxreadrate_button_label"));
  maxreadrate_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "maxreadrate_spinbutton"));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(phase_control_label_ccc), _("Phase Control"));
  gtk_button_set_label(GTK_BUTTON(phase1_check_button_ccc), _("Phase 1"));
  gtk_button_set_label(GTK_BUTTON(phase2_check_button_ccc), _("Phase 2"));
  gtk_button_set_label(GTK_BUTTON(phase3_check_button_ccc), _("Phase 3"));
  gtk_button_set_label(GTK_BUTTON(phase4_check_button_ccc), _("Phase 4"));
  gtk_button_set_label(GTK_BUTTON(divide_check_button_ccc), _("Divide"));
  gtk_button_set_label(GTK_BUTTON(divide2_check_button_ccc), _("Divide 2"));
  gtk_button_set_label(GTK_BUTTON(trim_check_button_ccc), _("Trim (overrides dividing)"));
  gtk_button_set_label(GTK_BUTTON(scrape_check_button_ccc), _("Scrape"));
  gtk_button_set_label(GTK_BUTTON(markbad_check_button_ccc), _("Mark Bad Head"));
  gtk_button_set_label(GTK_BUTTON(readbad_check_button_ccc), _("Read Bad Head"));
  gtk_button_set_label(GTK_BUTTON(rebuild_assist_check_button_ccc), _("Rebuild Assist"));
  gtk_button_set_label(GTK_BUTTON(reverse_check_button_ccc), _("Reverse"));
  gtk_button_set_label(GTK_BUTTON(skipfast_check_button_ccc), _("Skip Fast"));

  gtk_label_set_text(GTK_LABEL(retries_button_label_ccc), _("Retries"));
  gtk_label_set_text(GTK_LABEL(clustersize_button_label_ccc), _("Cluster Size (LBA)"));
  gtk_label_set_text(GTK_LABEL(inputoffset_button_label_ccc), _("Input Offset (LBA)"));
  gtk_label_set_text(GTK_LABEL(size_button_label_ccc), _("Size (LBA)"));
  gtk_label_set_text(GTK_LABEL(blocksize_button_label_ccc), _("Block size (LBA)"));
  gtk_label_set_text(GTK_LABEL(skipsize_button_label_ccc), _("Skip Size (LBA) phase-1-2-3"));
  gtk_label_set_text(GTK_LABEL(maxskipsize_button_label_ccc), _("Max Skip Size (LBA) phase-1-2"));
  gtk_label_set_text(GTK_LABEL(skipthreshold_button_label_ccc), _("Skip Threshold (ms) phase-1-2"));
  gtk_label_set_text(GTK_LABEL(rateskip_button_label_ccc), _("Rate Skip (kB/s) phase-3"));
  gtk_label_set_text(GTK_LABEL(exitonslow_button_label_ccc), _("Exit on Slow (kB/s) phase-1-2"));
  gtk_label_set_text(GTK_LABEL(exitonslowtime_button_label_ccc), _("Exit on Slow Time (sec) phase-1-2"));
  gtk_label_set_text(GTK_LABEL(sectorsize_button_label_ccc), _("Sector size (bytes)"));
  gtk_label_set_text(GTK_LABEL(alignment_button_label_ccc), _("Alignment offset (LBA)"));
  gtk_label_set_text(GTK_LABEL(maxreadrate_button_label_ccc), _("Max read rate (kB/s)"));

  gtk_widget_set_tooltip_text(phase_control_label_ccc, _("Select the phases to be used for the clone operation"));
  gtk_widget_set_tooltip_text(phase1_check_button_ccc, _("Enable Phase 1 (copy pass forward with skipping based on read errors)"));
  gtk_widget_set_tooltip_text(phase2_check_button_ccc, _("Enable Phase 2 (copy pass backward with skipping based on read errors)"));
  gtk_widget_set_tooltip_text(phase3_check_button_ccc, _("Enable Phase 3 (copy pass forward with skipping based on read speed)"));
  gtk_widget_set_tooltip_text(phase4_check_button_ccc, _("Enable Phase 4 (copy pass forward without skipping)"));
  gtk_widget_set_tooltip_text(divide_check_button_ccc, _("Enable Dividing (divide non-trimmed blocks into smaller blocks)"));
  gtk_widget_set_tooltip_text(divide2_check_button_ccc, _("Perform two dividing passes instead of one"));
  gtk_widget_set_tooltip_text(trim_check_button_ccc, _("Enable Trimming (read non-trimmed blocks one sector at a time forwards and backwards)"));
  gtk_widget_set_tooltip_text(scrape_check_button_ccc, _("Enable Scrape (read non-scraped blocks one sector at a time forwards)"));
  gtk_widget_set_tooltip_text(markbad_check_button_ccc, _("Enable Mark Bad Head (uses the skipping information during phases 1-2 to mark what is considered a bad head)"));
  gtk_widget_set_tooltip_text(readbad_check_button_ccc, _("Enable Read Bad Head (read sectors from heads marked as bad)"));
  gtk_widget_set_tooltip_text(rebuild_assist_check_button_ccc, _("Enable Rebuild Assist (use the Rebuild Assist phase instead of phase 1)"));
  gtk_widget_set_tooltip_text(reverse_check_button_ccc, _("Enable Reverse (reverse the direction of all passes)"));
  gtk_widget_set_tooltip_text(skipfast_check_button_ccc, _("Enable Skip Fast (use a more aggressive skipping algorithm)"));

  gtk_widget_set_tooltip_text(retries_button_label_ccc, _("Number of retry passes to perform"));
  gtk_widget_set_tooltip_text(clustersize_button_label_ccc, _("Number of sectors per read block in phases 1-4"));
  gtk_widget_set_tooltip_text(inputoffset_button_label_ccc, _("Number of sectors to skip at the beginning"));
  gtk_widget_set_tooltip_text(size_button_label_ccc, _("Number of sectors to copy"));
  gtk_widget_set_tooltip_text(blocksize_button_label_ccc, _("Number of logical sectors per physical sector. All reads will be aligned to this value."));
  gtk_widget_set_tooltip_text(skipsize_button_label_ccc, _("Number of sectors to skip in LBAs during phases 1-3. This number can grow during phases 1-2 to adjust to the head skipping algorithm."));
  gtk_widget_set_tooltip_text(maxskipsize_button_label_ccc, _("Maximum number of sectors to skip in LBAs during phases 1-2. The default is calculated as drive size / 1000 or 1GB, whichever is smaller."));
  gtk_widget_set_tooltip_text(skipthreshold_button_label_ccc, _("Number of milliseconds to wait for a read before triggering a skip in phases 1-2"));
  gtk_widget_set_tooltip_text(rateskip_button_label_ccc, _("Lowest read rate in kB/s before triggering a skip in phase 3"));
  gtk_widget_set_tooltip_text(exitonslow_button_label_ccc, _("Lowest read rate in kB/s before triggering an exit in phases 1-2"));
  gtk_widget_set_tooltip_text(exitonslowtime_button_label_ccc, _("Number of seconds to wait for a slow read before triggering an exit in phases 1-2"));
  gtk_widget_set_tooltip_text(sectorsize_button_label_ccc, _("Number of bytes per sector. This value will be detected automatically when choosing a source."));
  gtk_widget_set_tooltip_text(alignment_button_label_ccc, _("Number of logical sectors to align the source to. This value will be detected automatically when choosing a source."));
  gtk_widget_set_tooltip_text(maxreadrate_button_label_ccc, _("Limit for the maximum read rate in kB/s"));

  g_signal_connect(G_OBJECT(phase1_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASE1));
  g_signal_connect(G_OBJECT(phase2_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASE2));
  g_signal_connect(G_OBJECT(phase3_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASE3));
  g_signal_connect(G_OBJECT(phase4_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASE4));
  g_signal_connect(G_OBJECT(divide_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_DIVIDE));
  g_signal_connect(G_OBJECT(divide2_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_DIVIDE2));
  g_signal_connect(G_OBJECT(trim_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_TRIM));
  g_signal_connect(G_OBJECT(scrape_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_SCRAPE));
  g_signal_connect(G_OBJECT(markbad_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_MARKBAD));
  g_signal_connect(G_OBJECT(readbad_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_READBAD));
  g_signal_connect(G_OBJECT(rebuild_assist_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_REBUILDASSIST));
  g_signal_connect(G_OBJECT(reverse_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_REVERSE));
  g_signal_connect(G_OBJECT(skipfast_check_button_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_SKIPFAST));

  load_clone_settings_ccc();
  update_clone_button_settings_ccc();

  gtk_window_set_title(GTK_WINDOW(dialog), _("Clone Settings"));
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    clone_settings_ccc.retries = gtk_spin_button_get_value(GTK_SPIN_BUTTON(retries_spin_button_ccc));
    clone_settings_ccc.cluster_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(clustersize_spin_button_ccc));
    clone_settings_ccc.input_offset = gtk_spin_button_get_value(GTK_SPIN_BUTTON(inputoffset_spin_button_ccc));
    clone_settings_ccc.read_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(size_spin_button_ccc));
    clone_settings_ccc.block_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(blocksize_spin_button_ccc));
    clone_settings_ccc.min_skip_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(skipsize_spin_button_ccc));
    clone_settings_ccc.max_skip_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(maxskipsize_spin_button_ccc));
    clone_settings_ccc.skip_timeout = gtk_spin_button_get_value(GTK_SPIN_BUTTON(skipthreshold_spin_button_ccc)) * 1000;
    clone_settings_ccc.rate_skip = gtk_spin_button_get_value(GTK_SPIN_BUTTON(rateskip_spin_button_ccc)) * 1000;
    clone_settings_ccc.exit_on_slow = gtk_spin_button_get_value(GTK_SPIN_BUTTON(exitonslow_spin_button_ccc)) * 1000;
    clone_settings_ccc.exit_slow_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(exitonslowtime_spin_button_ccc)) * 1000;
    clone_settings_ccc.sector_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(sectorsize_spinbutton_ccc));
    clone_settings_ccc.block_offset = gtk_spin_button_get_value(GTK_SPIN_BUTTON(alignment_spinbutton_ccc));
    clone_settings_ccc.max_read_rate = gtk_spin_button_get_value(GTK_SPIN_BUTTON(maxreadrate_spinbutton_ccc)) * 1000;
    // clone_settings_ccc. = gtk_spin_button_get_value(GTK_SPIN_BUTTON());
    update_clone_settings_ccc();
    logfile_changed_ccc = true;
  }
  gtk_widget_destroy(dialog);
  update_display_ccc(0);
}

void open_advanced_settings_dialog_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "advanced_settings_dialog"));
  no_log_backup_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "no_log_backup_checkbutton"));
  force_mounted_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "force_mounted_checkbutton"));
  force_dangerous_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "force_dangerous_checkbutton"));
  enable_output_offset_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_output_offset_checkbutton"));
  output_offset_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "output_offset_spinbutton"));
  output_offset_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "output_offset_button_label"));
  enable_current_position_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_current_position_checkbutton"));
  current_position_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "current_position_spinbutton"));
  current_position_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "current_position_button_label"));
  action_on_error_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "action_on_error_label"));
  stop_on_error_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "stop_on_error_radio_button"));
  call_command_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "call_command_radio_button"));
  command_to_call_text_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "command_to_call_text"));
  test_command_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "test_command_button"));
  primary_relay_on_error_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_on_error_radio_button"));
  write_buffer_disable_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "write_buffer_disable_radio_button"));
  write_buffer_enable_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "write_buffer_enable_radio_button"));
  write_buffer_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "write_buffer_label"));
  disable_identify_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disable_identify_checkbutton"));
  pio_mode_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "pio_mode_checkbutton"));
  enable_rebuild_assist_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_rebuild_assist_checkbutton"));
  enable_process_chunk_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_process_chunk_checkbutton"));
  enable_read_twice_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_read_twice_checkbutton"));
  enable_retry_connecting_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_retry_connecting_checkbutton"));
  enable_scsi_write_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_scsi_write_checkbutton"));
  enable_phase_log_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_phase_log_checkbutton"));
  enable_output_sector_size_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_output_sector_size_checkbutton"));
  output_sector_size_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "output_sector_size_button_label"));
  driver_io_scsi_only_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_io_scsi_only_checkbutton"));
  use_physical_sector_size_for_virtual_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "use_physical_sector_size_for_virtual_checkbutton"));
  output_sector_size_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "output_sector_size_spinbutton"));
  driver_error_options_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_error_options_label"));
  driver_return_error_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_return_error_radio_button"));
  driver_return_zeros_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_return_zeros_radio_button"));
  driver_return_marked_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_return_marked_radio_button"));
  virtual_disk_device_name_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "virtual_disk_device_name_label"));
  virtual_disk_device_name_text_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "virtual_disk_device_name_text"));
  driver_minimum_cluster_size_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_minimum_cluster_size_button_label"));
  driver_minimum_cluster_size_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "driver_minimum_cluster_size_spinbutton"));
  use_color_statusbar_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "use_color_statusbar_checkbutton"));
  g_object_unref(builder);

  gtk_button_set_label(GTK_BUTTON(no_log_backup_checkbutton_ccc), _("Do not create backup log"));
  gtk_button_set_label(GTK_BUTTON(force_mounted_checkbutton_ccc), _("Force access of mounted disk (not recommended)"));
  gtk_button_set_label(GTK_BUTTON(force_dangerous_checkbutton_ccc), _("Force same controller / slave (not recommended)"));
  gtk_button_set_label(GTK_BUTTON(enable_output_offset_checkbutton_ccc), _("Enable changing output offset (use with caution)"));
  gtk_label_set_text(GTK_LABEL(output_offset_button_label_ccc), _("Output Offset (default value is -1, follow input offset)"));
  gtk_button_set_label(GTK_BUTTON(enable_current_position_checkbutton_ccc), _("Enable changing current position (can affect skipping algorithm)"));
  gtk_label_set_text(GTK_LABEL(current_position_button_label_ccc), _("Current position"));
  gtk_label_set_text(GTK_LABEL(action_on_error_label_ccc), _("Action to perform on major drive error:"));
  gtk_button_set_label(GTK_BUTTON(stop_on_error_radio_button_ccc), _("Stop cloning with error message"));
  gtk_button_set_label(GTK_BUTTON(call_command_radio_button_ccc), _("Call command:"));
  gtk_button_set_label(GTK_BUTTON(test_command_button_ccc), _("Test command"));
  gtk_button_set_label(GTK_BUTTON(primary_relay_on_error_radio_button_ccc), _("Activate primary relay"));
  gtk_button_set_label(GTK_BUTTON(write_buffer_disable_radio_button_ccc), _("Disabled (safer if there is a power loss)"));
  gtk_button_set_label(GTK_BUTTON(write_buffer_enable_radio_button_ccc), _("Enabled (faster)"));
  gtk_label_set_text(GTK_LABEL(write_buffer_label_ccc), _("Operating System write buffer (must disconnect to take effect)"));
  gtk_button_set_label(GTK_BUTTON(disable_identify_checkbutton_ccc), _("Do not perform identify when listing source devices"));
  gtk_button_set_label(GTK_BUTTON(pio_mode_checkbutton_ccc), _("PIO mode"));
  gtk_button_set_label(GTK_BUTTON(enable_rebuild_assist_checkbutton_ccc), _("Enable Rebuild Assist"));
  gtk_button_set_label(GTK_BUTTON(enable_process_chunk_checkbutton_ccc), _("Enable using ATA return to mark bad sectors"));
  gtk_button_set_label(GTK_BUTTON(enable_read_twice_checkbutton_ccc), _("Enable read twice on timeout"));
  gtk_button_set_label(GTK_BUTTON(enable_retry_connecting_checkbutton_ccc), _("Retry connecting on failure after relay power cycle"));
  gtk_button_set_label(GTK_BUTTON(enable_scsi_write_checkbutton_ccc), _("Enable SCSI write to destination (for odd sector size)"));
  gtk_button_set_label(GTK_BUTTON(enable_phase_log_checkbutton_ccc), _("Enable phase logs"));
  gtk_button_set_label(GTK_BUTTON(enable_output_sector_size_checkbutton_ccc), _("Enable output sector size adjustment"));
  gtk_label_set_text(GTK_LABEL(output_sector_size_button_label_ccc), _("Output sector size adjustment"));
  gtk_button_set_label(GTK_BUTTON(driver_io_scsi_only_checkbutton_ccc), _("Virtual Disk IO SCSI only"));
  gtk_button_set_label(GTK_BUTTON(use_physical_sector_size_for_virtual_checkbutton_ccc), _("Use physical sector size as logical for virtual disk"));
  gtk_button_set_label(GTK_BUTTON(driver_return_error_radio_button_ccc), _("Return read error (standard)"));
  gtk_button_set_label(GTK_BUTTON(driver_return_zeros_radio_button_ccc), _("Return zero filled data"));
  gtk_button_set_label(GTK_BUTTON(driver_return_marked_radio_button_ccc), _("Return mark filled data"));
  gtk_label_set_text(GTK_LABEL(driver_error_options_label_ccc), _("Virtual Disk Device Driver output options for read errors"));
  gtk_label_set_text(GTK_LABEL(driver_minimum_cluster_size_button_label_ccc), _("Virtual Disk minimum cluster read size (mode 3)"));
  gtk_label_set_text(GTK_LABEL(virtual_disk_device_name_label_ccc), _("Virtual Disk device name"));
  gtk_button_set_label(GTK_BUTTON(use_color_statusbar_checkbutton_ccc), _("Use button colors in bottom status bar"));

  gtk_widget_set_tooltip_text(GTK_WIDGET(no_log_backup_checkbutton_ccc), _("If checked, no log backups will be created when writing to the progess log (not recommended)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(force_mounted_checkbutton_ccc), _("Force working with the source even when it is mounted (not recommended)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(force_dangerous_checkbutton_ccc), _("Force working with the source even if it is detected that there is another drive on the same controller (not recommended)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_output_offset_checkbutton_ccc), _("Enable output offset adjustment. You must close and reopen the Advanced Settings to take effect."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(output_offset_button_label_ccc), _("Offset in LBAs to start writing to the destination (default -1 follows input offset)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_current_position_checkbutton_ccc), _("Enable current position adjustment. You must close and reopen the Advanced Settings to take effect."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(current_position_button_label_ccc), _("Current position in the recovery (it is not recommended to change this)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(action_on_error_label_ccc), _("A major driver error is something other than a typical read error. The Exit or Slow condition is considered a major error."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(stop_on_error_radio_button_ccc), _("Stop cloning and show an error message indicating the fault"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(call_command_radio_button_ccc), _("Call the specified command and continue cloning. If the command returns an error, the clone will be stopped."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(test_command_button_ccc), _("Test the specified command"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(primary_relay_on_error_radio_button_ccc), _("Activate the primary relay board and continue cloning"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(write_buffer_disable_radio_button_ccc), _("Disable the OS write buffer for writes to the destination. Safer in case of power loss, but slower."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(write_buffer_enable_radio_button_ccc), _("Enable the OS write buffer for writes to the destination. Faster, but may cause corruption in case of power loss."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(write_buffer_label_ccc), _("Enable or disable the OS write buffer for writes to the destination. Disabling it is safer in case of power loss, but slower."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(disable_identify_checkbutton_ccc), _("Disable the identify device command when listing source drives in Direct AHCI and IDE modes. This is to prevent a system lockup or error when listing possible source drives."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(pio_mode_checkbutton_ccc), _("Use PIO instead of DMA for reading the source drive."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_rebuild_assist_checkbutton_ccc), _("Enable Rebuild Assist. The Rebuild Assist selection in the Clone settings will have no effect if this is not checked."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_process_chunk_checkbutton_ccc), _("When a bad cluster is read in Passthrough ATA or Direct modes, the ATA return data can include the LBA of the first reported bad sector for the read. When this option is selected, data up to that LBA will be read, the problem sector marked as Bad, and the rest of the chunk marked as Non-Trimmed."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_read_twice_checkbutton_ccc), _("When enabled and the soft reset timeout is exceeded when reading, after the reset a second read attempt will be performed. The second read attempt will use the Retry reset time as the soft reset time for the this second read attempt."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_retry_connecting_checkbutton_ccc), _("If the device fails to identify after a relay power cycle, enabling this option will cause a second attempt to disconnect and reconnect the device."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_scsi_write_checkbutton_ccc), _("If the destination drive sector size is not a multiple of 512, you must enable this to be able to write to the drive."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_phase_log_checkbutton_ccc), _("When enabled a log with a time and phase stamp in the name will be created at the end of every phase."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(enable_output_sector_size_checkbutton_ccc), _("Enable output sector size adjustment. You must close and reopen the Advanced Settings to take effect."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(output_sector_size_button_label_ccc), _("Output sector adjustment in bytes (relative to the source sector size)"));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_io_scsi_only_checkbutton_ccc), _("Only use IO SCSI for reading the virtual disk. Normal block reads will return all zeros when this is enabled."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(use_physical_sector_size_for_virtual_checkbutton_ccc), _("This will use the physical sector size as the logical sector size when presenting the virtual disk to the operating system. The physical size is determined by the Block size setting in the Clone Settings."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_return_error_radio_button_ccc), _("Read errors will return with a standard I/O error."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_return_zeros_radio_button_ccc), _("Read errors will return zero filled data."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_return_marked_radio_button_ccc), _("Read errors will return with mark filled data."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_error_options_label_ccc), _("Options for how the virtual disk handles read errors as presented by the recovery."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(driver_minimum_cluster_size_button_label_ccc), _("When in virtual mode 3, this will be the minimum cluster read size. When cloning using a domain, this will also be the minimum cluster read size, so that small domain reads can be prevented if desired."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(virtual_disk_device_name_label_ccc), _("The name of the virtual disk in /dev. The default name is sdv (/dev/sdv). Note that if you choose a name that is already in use, it will cause a system crash. Also, you should choose a conventional name with the SDx format, or some software will not find or list it."));
  gtk_widget_set_tooltip_text(GTK_WIDGET(use_color_statusbar_checkbutton_ccc), _("This option will turn on using colors on the bottom status bar (may not work on some systems)."));

  if (!advanced_settings_ccc.enable_output_offset)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(output_offset_spinbutton_ccc), FALSE);
  }
  if (!advanced_settings_ccc.enable_current_position)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(current_position_spinbutton_ccc), FALSE);
  }
  if (!advanced_settings_ccc.enable_output_sector_size)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(output_sector_size_spinbutton_ccc), FALSE);
  }

  gtk_entry_set_max_length(GTK_ENTRY(command_to_call_text_ccc), MAX_CALL_LENGTH);
  gtk_entry_set_max_length(GTK_ENTRY(virtual_disk_device_name_text_ccc), MAX_DEVICE_NAME_LENGTH);

  g_signal_connect(G_OBJECT(no_log_backup_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_NOLOGBACK));
  g_signal_connect(G_OBJECT(force_mounted_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_FORCE));
  g_signal_connect(G_OBJECT(force_dangerous_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_FORCEDANGEROUS));
  g_signal_connect(G_OBJECT(enable_output_offset_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_OFFSET));
  g_signal_connect(G_OBJECT(enable_current_position_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_POSITION));
  g_signal_connect(G_OBJECT(disable_identify_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_DONTIDENTIFY));
  g_signal_connect(G_OBJECT(pio_mode_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PIOMODE));
  g_signal_connect(G_OBJECT(enable_rebuild_assist_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLEREBUILDASSIST));
  g_signal_connect(G_OBJECT(enable_process_chunk_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLEPROCESSCHUNK));
  g_signal_connect(G_OBJECT(enable_read_twice_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLEREADTWICE));
  g_signal_connect(G_OBJECT(enable_retry_connecting_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLERETRYCONNECTING));
  g_signal_connect(G_OBJECT(enable_scsi_write_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLESCSIWRITE));
  g_signal_connect(G_OBJECT(enable_phase_log_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLEPHASELOGS));
  g_signal_connect(G_OBJECT(enable_output_sector_size_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_ENABLEOUTPUTSECTOR));
  g_signal_connect(G_OBJECT(driver_io_scsi_only_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_IOSCSIONLY));
  g_signal_connect(G_OBJECT(use_physical_sector_size_for_virtual_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_USEPHYSICALSECTORSIZE));
  g_signal_connect(G_OBJECT(use_color_statusbar_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_COLORSTATUSBAR));
  // g_signal_connect(G_OBJECT(), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER());
  // g_signal_connect(test_command_button_ccc, "clicked", G_CALLBACK(test_command_ccc), NULL);

  load_advanced_settings_ccc();
  gtk_entry_set_text(GTK_ENTRY(command_to_call_text_ccc), advanced_settings_ccc.command_to_call);
  gtk_entry_set_text(GTK_ENTRY(virtual_disk_device_name_text_ccc), advanced_settings_ccc.virtual_disk_device_name);
  update_advanced_button_settings_ccc();

  if (direct_mode_ccc)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(disable_identify_checkbutton_ccc), TRUE);
    gtk_widget_set_sensitive(GTK_WIDGET(pio_mode_checkbutton_ccc), TRUE);
  }
  else
  {
    gtk_widget_set_sensitive(GTK_WIDGET(disable_identify_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(pio_mode_checkbutton_ccc), FALSE);
  }

  gtk_window_set_title(GTK_WINDOW(dialog), _("Advanced Settings"));

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    advanced_settings_ccc.output_offset = gtk_spin_button_get_value(GTK_SPIN_BUTTON(output_offset_spinbutton_ccc));
    advanced_settings_ccc.current_position = gtk_spin_button_get_value(GTK_SPIN_BUTTON(current_position_spinbutton_ccc));
    advanced_settings_ccc.stop_on_error = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_on_error_radio_button_ccc));
    advanced_settings_ccc.call_command = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(call_command_radio_button_ccc));
    advanced_settings_ccc.activate_primary_relay = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(primary_relay_on_error_radio_button_ccc));
    advanced_settings_ccc.write_buffer_disable = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(write_buffer_disable_radio_button_ccc));
    advanced_settings_ccc.write_buffer_enable = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(write_buffer_enable_radio_button_ccc));
    advanced_settings_ccc.driver_return_error = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(driver_return_error_radio_button_ccc));
    advanced_settings_ccc.driver_return_zeros = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(driver_return_zeros_radio_button_ccc));
    advanced_settings_ccc.driver_return_marked = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(driver_return_marked_radio_button_ccc));
    advanced_settings_ccc.output_sector_adjustment = gtk_spin_button_get_value(GTK_SPIN_BUTTON(output_sector_size_spinbutton_ccc));
    advanced_settings_ccc.driver_minimum_cluster_size = gtk_spin_button_get_value(GTK_SPIN_BUTTON(driver_minimum_cluster_size_spinbutton_ccc));
    const gchar *entry_text;
    entry_text = gtk_entry_get_text(GTK_ENTRY(command_to_call_text_ccc));
    strcpy(advanced_settings_ccc.command_to_call, entry_text);
    const gchar *entry_text2;
    entry_text2 = gtk_entry_get_text(GTK_ENTRY(virtual_disk_device_name_text_ccc));
    strcpy(advanced_settings_ccc.virtual_disk_device_name, entry_text2);
    update_advanced_settings_ccc();
    logfile_changed_ccc = true;
  }
  gtk_widget_destroy(dialog);
  update_display_ccc(0);
}

void open_timer_settings_dialog_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "timer_settings_dialog"));
  timer_settings_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "timer_settings_label"));
  timer_settings_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "timer_settings_info_label"));
  initial_busy_wait_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "initial_busy_wait_time_button_label"));
  initial_busy_wait_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "initial_busy_wait_time_spinbutton"));
  busy_wait_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "busy_wait_time_button_label"));
  busy_wait_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "busy_wait_time_spinbutton"));
  soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "soft_reset_time_button_label"));
  soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "soft_reset_time_spinbutton"));
  hard_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "hard_reset_time_button_label"));
  hard_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "hard_reset_time_spinbutton"));
  power_cycle_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "power_cycle_time_button_label"));
  power_cycle_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "power_cycle_time_spinbutton"));
  general_timout_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "general_timout_button_label"));
  general_timeout_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "general_timeout_spinbutton"));
  action_power_cycle_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "action_power_cycle_label"));
  stop_on_power_cycle_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "stop_on_power_cycle_radio_button"));
  call_power_command_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "call_power_command_radio_button"));
  power_command_to_call_text_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "power_command_to_call_text"));
  test_power_command_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "test_power_command_button"));
  primary_relay_power_cycle_radio_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_power_cycle_radio_button"));
  phase_timers_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase_timers_label"));
  phase_timers_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "phase_timers_checkbutton"));
  p12_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p12_soft_reset_time_button_label"));
  p12_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p12_soft_reset_time_spinbutton"));
  p3_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p3_soft_reset_time_button_label"));
  p3_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p3_soft_reset_time_spinbutton"));
  p4_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p4_soft_reset_time_button_label"));
  p4_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "p4_soft_reset_time_spinbutton"));
  td_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "td_soft_reset_time_button_label"));
  td_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "td_soft_reset_time_spinbutton"));
  d2_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "d2_soft_reset_time_button_label"));
  d2_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "d2_soft_reset_time_spinbutton"));
  sc_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "sc_soft_reset_time_button_label"));
  sc_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "sc_soft_reset_time_spinbutton"));
  rt_soft_reset_time_button_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "rt_soft_reset_time_button_label"));
  rt_soft_reset_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "rt_soft_reset_time_spinbutton"));
  always_wait_for_reset_timers_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "always_wait_for_reset_timers_checkbutton"));
  usb_resets_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "usb_resets_label"));
  enable_usb_bulk_reset_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_usb_bulk_reset_checkbutton"));
  enable_usb_soft_reset_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_usb_soft_reset_checkbutton"));
  enable_usb_hard_reset_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_usb_hard_reset_checkbutton"));
  enable_usb_port_reset_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "enable_usb_port_reset_checkbutton"));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(timer_settings_label_ccc), "");
  gtk_label_set_text(GTK_LABEL(timer_settings_info_label_ccc), _("These timer settings are only for Direct IDE and Direct AHCI modes.\nThey have no effect with the passthrough modes.\n"));
  gtk_label_set_text(GTK_LABEL(initial_busy_wait_time_button_label_ccc), _("Initial busy wait time (ms)"));
  gtk_label_set_text(GTK_LABEL(busy_wait_time_button_label_ccc), _("Busy wait time (ms)"));
  gtk_label_set_text(GTK_LABEL(soft_reset_time_button_label_ccc), _("Soft reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(hard_reset_time_button_label_ccc), _("Hard reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(power_cycle_time_button_label_ccc), _("Reset timeout (ms)"));
  gtk_label_set_text(GTK_LABEL(general_timout_button_label_ccc), _("General timeout (ms)"));
  gtk_label_set_text(GTK_LABEL(action_power_cycle_label_ccc), _("Action for reset timeout"));
  gtk_button_set_label(GTK_BUTTON(stop_on_power_cycle_radio_button_ccc), _("Do nothing"));
  gtk_button_set_label(GTK_BUTTON(call_power_command_radio_button_ccc), _("Call command:"));
  gtk_button_set_label(GTK_BUTTON(test_power_command_button_ccc), _("Test command"));
  gtk_button_set_label(GTK_BUTTON(primary_relay_power_cycle_radio_button_ccc), _("Activate primary relay"));
  gtk_label_set_text(GTK_LABEL(phase_timers_label_ccc), _("Phase timers (soft reset timers)"));
  gtk_button_set_label(GTK_BUTTON(phase_timers_checkbutton_ccc), _("Enable phase timers"));
  gtk_label_set_text(GTK_LABEL(p12_soft_reset_time_button_label_ccc), _("Phase 1-2 reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(p3_soft_reset_time_button_label_ccc), _("Phase 3 reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(p4_soft_reset_time_button_label_ccc), _("Phase 4 reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(td_soft_reset_time_button_label_ccc), _("Trim/Divide reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(d2_soft_reset_time_button_label_ccc), _("Divide 2 reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(sc_soft_reset_time_button_label_ccc), _("Scrape reset time (ms)"));
  gtk_label_set_text(GTK_LABEL(rt_soft_reset_time_button_label_ccc), _("Retry reset time (ms)"));
  gtk_button_set_label(GTK_BUTTON(always_wait_for_reset_timers_checkbutton_ccc), _("Always wait for reset timers"));
  gtk_label_set_text(GTK_LABEL(usb_resets_label_ccc), _("USB reset choices"));
  gtk_button_set_label(GTK_BUTTON(enable_usb_bulk_reset_checkbutton_ccc), _("Enable USB bulk reset"));
  gtk_button_set_label(GTK_BUTTON(enable_usb_soft_reset_checkbutton_ccc), _("Enable USB soft reset"));
  gtk_button_set_label(GTK_BUTTON(enable_usb_hard_reset_checkbutton_ccc), _("Enable USB hard reset"));
  gtk_button_set_label(GTK_BUTTON(enable_usb_port_reset_checkbutton_ccc), _("Enable USB port reset"));

  gtk_entry_set_max_length(GTK_ENTRY(power_command_to_call_text_ccc), MAX_CALL_LENGTH);

  g_signal_connect(G_OBJECT(phase_timers_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASETIMERS));

  load_timer_settings_ccc();
  gtk_entry_set_text(GTK_ENTRY(power_command_to_call_text_ccc), timer_settings_ccc.power_command_to_call);
  update_timer_button_settings_ccc();

  if (!direct_mode_ccc && !usb_mode_ccc)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(initial_busy_wait_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(busy_wait_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(power_cycle_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(stop_on_power_cycle_radio_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(call_power_command_radio_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(test_power_command_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(power_command_to_call_text_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(primary_relay_power_cycle_radio_button_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(phase_timers_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(p12_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(p3_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(p4_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(td_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(d2_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(sc_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(rt_soft_reset_time_spinbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(always_wait_for_reset_timers_checkbutton_ccc), FALSE);
  }
  if (!usb_mode_ccc)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(enable_usb_bulk_reset_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(enable_usb_soft_reset_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(enable_usb_hard_reset_checkbutton_ccc), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(enable_usb_port_reset_checkbutton_ccc), FALSE);
  }
  if (!ahci_mode_ccc && !usb_mode_ccc)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(hard_reset_time_spinbutton_ccc), FALSE);
  }

  gtk_window_set_title(GTK_WINDOW(dialog), _("Timer Settings"));

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    timer_settings_ccc.initial_busy_wait_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(initial_busy_wait_time_spinbutton_ccc));
    timer_settings_ccc.busy_wait_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(busy_wait_time_spinbutton_ccc));
    timer_settings_ccc.soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.hard_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(hard_reset_time_spinbutton_ccc));
    timer_settings_ccc.power_cycle_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(power_cycle_time_spinbutton_ccc));
    timer_settings_ccc.general_timeout = gtk_spin_button_get_value(GTK_SPIN_BUTTON(general_timeout_spinbutton_ccc));
    timer_settings_ccc.stop_on_power_cycle = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(stop_on_power_cycle_radio_button_ccc));
    timer_settings_ccc.call_power_command = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(call_power_command_radio_button_ccc));
    timer_settings_ccc.power_cycle_primary_relay = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(primary_relay_power_cycle_radio_button_ccc));

    timer_settings_ccc.p12_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(p12_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.p3_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(p3_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.p4_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(p4_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.td_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(td_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.d2_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(d2_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.sc_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(sc_soft_reset_time_spinbutton_ccc));
    timer_settings_ccc.rt_soft_reset_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(rt_soft_reset_time_spinbutton_ccc));

    timer_settings_ccc.always_wait_for_reset_timers = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(always_wait_for_reset_timers_checkbutton_ccc));

    timer_settings_ccc.usb_bulk_reset_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enable_usb_bulk_reset_checkbutton_ccc));
    timer_settings_ccc.usb_soft_reset_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enable_usb_soft_reset_checkbutton_ccc));
    timer_settings_ccc.usb_hard_reset_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enable_usb_hard_reset_checkbutton_ccc));
    timer_settings_ccc.usb_port_reset_enabled = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enable_usb_port_reset_checkbutton_ccc));

    const gchar *entry_text;
    entry_text = gtk_entry_get_text(GTK_ENTRY(power_command_to_call_text_ccc));
    strcpy(timer_settings_ccc.power_command_to_call, entry_text);
    update_timer_settings_ccc();
    logfile_changed_ccc = true;
  }
  gtk_widget_destroy(dialog);
  update_display_ccc(0);
}

int open_ports_dialog_ccc(char *current_ports)
{
  disabled_ports_changed_ccc = 0;
  int confirm = 0;
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "disable_ports_dialog"));
  disable_ports_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disable_ports_label"));
  disable_ports_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "disable_ports_info_label"));
  current_ports_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "current_ports_label"));
  current_ports_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "current_ports_info_label"));
  set_disabled_ports_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "set_disabled_ports_label"));
  set_disabled_ports_text_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "set_disabled_ports_text"));
  updated_ports_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "updated_ports_label"));
  updated_ports_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "updated_ports_info_label"));
  update_ports_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "update_ports_button"));
  g_object_unref(builder);

  new_ports_ccc[0] = '\0';
  char portsinfo[4096] = "";
  snprintf(portsinfo, sizeof(portsinfo), "%s%s", _("Disable ports for AHCI mode to hide a drive from the operating system.\nWarning! If you disable the port for the operating system drive,\nthe system will not be able to boot!\n"),
           _("Enter the ports you wish to be disabled as integers separated by spaces.\nIt is best that the port numbers are in order from lowest to highest.\nYou can find port information by listing source drives in AHCI mode.\n"));
  gtk_label_set_text(GTK_LABEL(disable_ports_info_label_ccc), portsinfo);
  gtk_label_set_text(GTK_LABEL(disable_ports_label_ccc), _("Disable Ports"));
  gtk_label_set_text(GTK_LABEL(current_ports_label_ccc), _("Current disabled ports (GRUB data)"));
  gtk_label_set_text(GTK_LABEL(current_ports_info_label_ccc), current_ports);
  gtk_label_set_text(GTK_LABEL(set_disabled_ports_label_ccc), _("Set disabled ports"));
  gtk_label_set_text(GTK_LABEL(updated_ports_label_ccc), _("Updated disabled ports (GRUB data)"));
  gtk_label_set_text(GTK_LABEL(updated_ports_info_label_ccc), current_ports);
  gtk_button_set_label(GTK_BUTTON(update_ports_button_ccc), _("Update ports"));

  gtk_window_set_title(GTK_WINDOW(dialog), _("Disable Ports"));

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    if (disabled_ports_changed_ccc)
    {
      confirm = 1;
    }
  }
  gtk_widget_destroy(dialog);
  return confirm;
}

int set_lun_dialog_ccc(int max_lun)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "select_lun_dialog"));
  select_lun_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "select_lun_label"));
  select_lun_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "select_lun_info_label"));
  lun_values_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "lun_values_label"));
  lun_values_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "lun_values_info_label"));
  set_current_lun_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "set_current_lun_label"));
  current_lun_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "current_lun_spinbutton"));
  g_object_unref(builder);

  char luninfo[256] = "";
  snprintf(luninfo, sizeof(luninfo), "0 - %d", max_lun);
  gtk_label_set_text(GTK_LABEL(select_lun_label_ccc), _("Select Logical Unit"));
  gtk_label_set_text(GTK_LABEL(select_lun_info_label_ccc), _("This device has more than 1 logical unit.\nPlease choose which logical unit."));
  gtk_label_set_text(GTK_LABEL(lun_values_label_ccc), _("Possible Logical Units"));
  gtk_label_set_text(GTK_LABEL(lun_values_info_label_ccc), luninfo);
  gtk_label_set_text(GTK_LABEL(set_current_lun_label_ccc), _("Set Logical Unit"));

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, max_lun, 1, 1, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(current_lun_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(current_lun_spinbutton_ccc), usb_lun_ccc);

  gtk_window_set_title(GTK_WINDOW(dialog), _("Select Logical Unit"));

  int ret = 1;
  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    usb_lun_ccc = gtk_spin_button_get_value(GTK_SPIN_BUTTON(current_lun_spinbutton_ccc));
    usb_lun_set_ccc = 1;
    ret = 0;
    fprintf(stdout, "lun=%d\n", usb_lun_ccc);
  }
  gtk_widget_destroy(dialog);
  return ret;
}

void open_primary_relay_dialog_ccc(void)
{
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_settings_dialog"));
  primary_relay_settings_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_settings_label"));
  primary_relay_settings_info_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_settings_info_label"));
  label_current_primary_relay_board_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "label_current_primary_relay_board"));
  data_current_relay_board_a_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "data_current_relay_board_a"));
  primary_relay_board_settings_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_board_settings_label"));
  primary_relay_activation_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_activation_label"));
  activate_primary_relay1_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay1_checkbutton"));
  activate_primary_relay2_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay2_checkbutton"));
  activate_primary_relay3_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay3_checkbutton"));
  activate_primary_relay4_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay4_checkbutton"));
  activate_primary_relay5_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay5_checkbutton"));
  activate_primary_relay6_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay6_checkbutton"));
  activate_primary_relay7_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay7_checkbutton"));
  activate_primary_relay8_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay8_checkbutton"));
  primary_relay_deactivation_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_deactivation_label"));
  deactivate_primary_relay1_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay1_checkbutton"));
  deactivate_primary_relay2_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay2_checkbutton"));
  deactivate_primary_relay3_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay3_checkbutton"));
  deactivate_primary_relay4_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay4_checkbutton"));
  deactivate_primary_relay5_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay5_checkbutton"));
  deactivate_primary_relay6_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay6_checkbutton"));
  deactivate_primary_relay7_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay7_checkbutton"));
  deactivate_primary_relay8_checkbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay8_checkbutton"));
  primary_relay_activate_time_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_activate_time_label"));
  primary_relay_energize_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_energize_time_spinbutton"));
  primary_relay_delay_time_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_delay_time_label"));
  primary_relay_delay_time_spinbutton_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "primary_relay_delay_time_spinbutton"));
  test_primary_relay_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "test_primary_relay_button"));
  activate_primary_relay_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "activate_primary_relay_button"));
  deactivate_primary_relay_button_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "deactivate_primary_relay_button"));
  // = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  // = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  // = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  // = GTK_WIDGET (gtk_builder_get_object (builder, ""));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(primary_relay_settings_label_ccc), "");
  gtk_label_set_text(GTK_LABEL(primary_relay_settings_info_label_ccc), _("Primary relay board settings"));
  gtk_label_set_text(GTK_LABEL(label_current_primary_relay_board_ccc), _("Current relay board"));
  gtk_label_set_text(GTK_LABEL(primary_relay_board_settings_label_ccc), _("Relay board settings"));
  gtk_label_set_text(GTK_LABEL(primary_relay_activation_label_ccc), _("Activation condition"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay1_checkbutton_ccc), _("Energize relay 1"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay2_checkbutton_ccc), _("Energize relay 2"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay3_checkbutton_ccc), _("Energize relay 3"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay4_checkbutton_ccc), _("Energize relay 4"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay5_checkbutton_ccc), _("Energize relay 5"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay6_checkbutton_ccc), _("Energize relay 6"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay7_checkbutton_ccc), _("Energize relay 7"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay8_checkbutton_ccc), _("Energize relay 8"));
  gtk_label_set_text(GTK_LABEL(primary_relay_deactivation_label_ccc), _("Deactivation condition"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay1_checkbutton_ccc), _("Energize relay 1"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay2_checkbutton_ccc), _("Energize relay 2"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay3_checkbutton_ccc), _("Energize relay 3"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay4_checkbutton_ccc), _("Energize relay 4"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay5_checkbutton_ccc), _("Energize relay 5"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay6_checkbutton_ccc), _("Energize relay 6"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay7_checkbutton_ccc), _("Energize relay 7"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay8_checkbutton_ccc), _("Energize relay 8"));
  gtk_label_set_text(GTK_LABEL(primary_relay_activate_time_label_ccc), _("Activation time (sec)"));
  gtk_label_set_text(GTK_LABEL(primary_relay_delay_time_label_ccc), _("Post activation delay time (sec)"));
  gtk_button_set_label(GTK_BUTTON(test_primary_relay_button_ccc), _("Test relay operation"));
  gtk_button_set_label(GTK_BUTTON(activate_primary_relay_button_ccc), _("Activate (Power Off)"));
  gtk_button_set_label(GTK_BUTTON(deactivate_primary_relay_button_ccc), _("Deactivate (Power On)"));

  // gtk_entry_set_max_length (GTK_ENTRY (power_command_to_call_text_ccc), MAX_CALL_LENGTH);

  // g_signal_connect(G_OBJECT(phase_timers_checkbutton_ccc), "toggled", G_CALLBACK(set_state_from_button_ccc), GINT_TO_POINTER(BUTTONID_PHASETIMERS));

  load_primary_relay_settings_ccc();
  gtk_label_set_text(GTK_LABEL(data_current_relay_board_a_ccc), primary_relay_settings_ccc.primary_relay_name);
  update_primary_relay_button_settings_ccc();

  gtk_window_set_title(GTK_WINDOW(dialog), _("Primary Relay Settings"));

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    update_primary_relay_settings_from_buttons_ccc();

    update_primary_relay_settings_ccc();
    logfile_changed_ccc = true;
  }
  gtk_widget_destroy(dialog);
  update_display_ccc(0);
}

void update_primary_relay_settings_from_buttons_ccc(void)
{
  primary_relay_settings_ccc.activate_primary_relay1 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay1_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay2 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay2_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay3 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay3_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay4 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay4_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay5 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay5_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay6 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay6_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay7 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay7_checkbutton_ccc));
  primary_relay_settings_ccc.activate_primary_relay8 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(activate_primary_relay8_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay1 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay1_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay2 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay2_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay3 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay3_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay4 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay4_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay5 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay5_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay6 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay6_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay7 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay7_checkbutton_ccc));
  primary_relay_settings_ccc.deactivate_primary_relay8 = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay8_checkbutton_ccc));
  primary_relay_settings_ccc.primary_relay_activation_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(primary_relay_energize_time_spinbutton_ccc));
  primary_relay_settings_ccc.primary_relay_delay_time = gtk_spin_button_get_value(GTK_SPIN_BUTTON(primary_relay_delay_time_spinbutton_ccc));

  // = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON());
  // = gtk_spin_button_get_value(GTK_SPIN_BUTTON());
}

void do_test_primary_relay_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  int error = 0;
  bool activate_primary_relay1_bak = primary_relay_settings_ccc.activate_primary_relay1;
  bool activate_primary_relay2_bak = primary_relay_settings_ccc.activate_primary_relay2;
  bool activate_primary_relay3_bak = primary_relay_settings_ccc.activate_primary_relay3;
  bool activate_primary_relay4_bak = primary_relay_settings_ccc.activate_primary_relay4;
  bool activate_primary_relay5_bak = primary_relay_settings_ccc.activate_primary_relay5;
  bool activate_primary_relay6_bak = primary_relay_settings_ccc.activate_primary_relay6;
  bool activate_primary_relay7_bak = primary_relay_settings_ccc.activate_primary_relay7;
  bool activate_primary_relay8_bak = primary_relay_settings_ccc.activate_primary_relay8;
  bool deactivate_primary_relay1_bak = primary_relay_settings_ccc.deactivate_primary_relay1;
  bool deactivate_primary_relay2_bak = primary_relay_settings_ccc.deactivate_primary_relay2;
  bool deactivate_primary_relay3_bak = primary_relay_settings_ccc.deactivate_primary_relay3;
  bool deactivate_primary_relay4_bak = primary_relay_settings_ccc.deactivate_primary_relay4;
  bool deactivate_primary_relay5_bak = primary_relay_settings_ccc.deactivate_primary_relay5;
  bool deactivate_primary_relay6_bak = primary_relay_settings_ccc.deactivate_primary_relay6;
  bool deactivate_primary_relay7_bak = primary_relay_settings_ccc.deactivate_primary_relay7;
  bool deactivate_primary_relay8_bak = primary_relay_settings_ccc.deactivate_primary_relay8;
  unsigned long long primary_relay_activation_time_bak = primary_relay_settings_ccc.primary_relay_activation_time;
  unsigned long long primary_relay_delay_time_bak = primary_relay_settings_ccc.primary_relay_delay_time;

  update_primary_relay_settings_from_buttons_ccc();
  update_primary_relay_settings_ccc();

  g_print("activate primary relay\n");
  if (activate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    error = 1;
  }

  // wait to deactivate
  if (!error)
  {
    unsigned int i;
    for (i = primary_relay_settings_ccc.primary_relay_activation_time; i > 0; i--)
    {
      g_print("%d  ", i);
      do_nanosleep_ccc(1000000000);
      update_display_ccc(0);
    }
    g_print("\n");
    g_print("deactivate primary relay\n");
    if (deactivate_primary_relay_ccc())
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
      error = 1;
    }
  }

  // wait for delay time
  if (!error)
  {
    g_print("wait for delay time\n");
    unsigned int i;
    for (i = primary_relay_settings_ccc.primary_relay_delay_time; i > 0; i--)
    {
      g_print("%d  ", i);
      do_nanosleep_ccc(1000000000);
      update_display_ccc(0);
    }
    g_print("\n");
    g_print("relay test complete\n");
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Operation completed successfully\n"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
    clear_error_message_ccc();
  }

  primary_relay_settings_ccc.activate_primary_relay1 = activate_primary_relay1_bak;
  primary_relay_settings_ccc.activate_primary_relay2 = activate_primary_relay2_bak;
  primary_relay_settings_ccc.activate_primary_relay3 = activate_primary_relay3_bak;
  primary_relay_settings_ccc.activate_primary_relay4 = activate_primary_relay4_bak;
  primary_relay_settings_ccc.activate_primary_relay5 = activate_primary_relay5_bak;
  primary_relay_settings_ccc.activate_primary_relay6 = activate_primary_relay6_bak;
  primary_relay_settings_ccc.activate_primary_relay7 = activate_primary_relay7_bak;
  primary_relay_settings_ccc.activate_primary_relay8 = activate_primary_relay8_bak;
  primary_relay_settings_ccc.deactivate_primary_relay1 = deactivate_primary_relay1_bak;
  primary_relay_settings_ccc.deactivate_primary_relay2 = deactivate_primary_relay2_bak;
  primary_relay_settings_ccc.deactivate_primary_relay3 = deactivate_primary_relay3_bak;
  primary_relay_settings_ccc.deactivate_primary_relay4 = deactivate_primary_relay4_bak;
  primary_relay_settings_ccc.deactivate_primary_relay5 = deactivate_primary_relay5_bak;
  primary_relay_settings_ccc.deactivate_primary_relay6 = deactivate_primary_relay6_bak;
  primary_relay_settings_ccc.deactivate_primary_relay7 = deactivate_primary_relay7_bak;
  primary_relay_settings_ccc.deactivate_primary_relay8 = deactivate_primary_relay8_bak;
  primary_relay_settings_ccc.primary_relay_activation_time = primary_relay_activation_time_bak;
  primary_relay_settings_ccc.primary_relay_delay_time = primary_relay_delay_time_bak;
  update_primary_relay_settings_ccc();
}

int cycle_primary_relay_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return -1;
  }

  g_print("activate primary relay ");
  if (activate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return -1;
  }

  // wait to deactivate
  unsigned int i;
  for (i = primary_relay_activation_time_ccc; i > 0; i--)
  {
    g_print("%d ", i);
    do_nanosleep_ccc(1000000000);
  }
  g_print("\n");
  g_print("deactivate and wait ");
  if (deactivate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return -1;
  }

  // wait for delay time
  for (i = primary_relay_delay_time_ccc; i > 0; i--)
  {
    g_print("%d ", i);
    do_nanosleep_ccc(1000000000);
  }
  g_print("done\n");

  return 0;
}

void update_ports_ccc(void)
{
  const gchar *entry_text;
  entry_text = gtk_entry_get_text(GTK_ENTRY(set_disabled_ports_text_ccc));
  // fprintf (stdout, "%s\n", entry_text);    //debug
  char line[256];
  char rawport[16][256];
  strncpy(line, entry_text, 255);
  strcpy(new_ports_ccc, "libata.force=");
  int first = 1;
  int count = 0;
  int scanline = sscanf(line, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", rawport[0], rawport[1], rawport[2], rawport[3], rawport[4], rawport[5], rawport[6], rawport[7], rawport[8], rawport[9], rawport[10], rawport[11], rawport[12], rawport[13], rawport[14], rawport[15]);
  while (scanline > 0)
  {
    unsigned int port = strtoull(rawport[count], NULL, 0);
    char temp[256];
    if (first)
    {
      snprintf(temp, sizeof(temp), "%u:disable", port);
    }
    else
    {
      snprintf(temp, sizeof(temp), ",%u:disable", port);
    }
    strncat(new_ports_ccc, temp, sizeof(new_ports_ccc) - strlen(new_ports_ccc) - 1);
    first = 0;
    count++;
    scanline--;
  }
  gtk_label_set_text(GTK_LABEL(updated_ports_info_label_ccc), new_ports_ccc);
  disabled_ports_changed_ccc = 1;
}

int open_confirmation_dialog_ccc(char *message)
{
  int confirm = 0;
  GtkBuilder *builder = gtk_builder_new();
  GError *err = NULL; // It is mandatory to initialize to NULL
  if (0 == gtk_builder_add_from_string(builder, (const gchar *)opensuperclone_glade, opensuperclone_glade_len, &err))
  {
    fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  }
  gtk_builder_connect_signals(builder, NULL);
  GtkWidget *dialog = GTK_WIDGET(gtk_builder_get_object(builder, "confirmation_dialog"));
  confirmation_box_label_ccc = GTK_WIDGET(gtk_builder_get_object(builder, "confirmation_box_label"));
  g_object_unref(builder);

  gtk_label_set_text(GTK_LABEL(confirmation_box_label_ccc), message);

  gtk_window_set_title(GTK_WINDOW(dialog), _("Confirm Operation"));

  if (gtk_dialog_run(GTK_DIALOG(dialog)) == 5)
  {
    confirm = 1;
  }
  gtk_widget_destroy(dialog);
  return confirm;
}

void test_command_ccc(void)
{
  const gchar *entry_text;
  entry_text = gtk_entry_get_text(GTK_ENTRY(command_to_call_text_ccc));
  int ret = system(entry_text);
  if (ret)
  {
    int status = WEXITSTATUS(ret);
    int signal = WTERMSIG(ret);
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The called command failed with exit signal / status"));
    message_error_ccc(tempmessage_ccc);
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, " (%d / %d)", signal, status);
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The command completed normally"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
    clear_error_message_ccc();
  }
}

void test_power_command_ccc(void)
{
  const gchar *entry_text;
  entry_text = gtk_entry_get_text(GTK_ENTRY(power_command_to_call_text_ccc));
  int ret = system(entry_text);
  if (ret)
  {
    int status = WEXITSTATUS(ret);
    int signal = WTERMSIG(ret);
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The called command failed with exit signal / status"));
    message_error_ccc(tempmessage_ccc);
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, " (%d / %d)", signal, status);
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The command completed normally"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
    clear_error_message_ccc();
  }
}

void activate_status_buttons_ccc(void)
{
  gtk_widget_set_sensitive(GTK_WIDGET(button_bsy_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_drdy_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_df_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_dsc_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_drq_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_corr_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_idx_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_err_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_status_separator_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_bbk_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_unc_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_mc_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_idnf_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_mcr_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_abrt_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_tk0nf_ccc), TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_amnf_ccc), TRUE);

  gdk_rgba_parse(&button_color_ccc, GTKCOLOR_GRAY);
  gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);

  gdk_rgba_parse(&button_color_ccc, GTKCOLOR_WHITE);
  gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);

  gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);

  gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
  gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
}

void deactivate_status_buttons_ccc(void)
{
  gtk_widget_set_sensitive(GTK_WIDGET(button_bsy_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_drdy_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_df_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_dsc_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_drq_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_corr_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_idx_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_err_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_status_separator_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_bbk_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_unc_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_mc_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_idnf_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_mcr_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_abrt_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_tk0nf_ccc), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button_amnf_ccc), FALSE);
}

void update_status_buttons_ccc(void)
{
  if (!scsi_passthrough_ccc && !fill_mode_ccc && !generic_mode_ccc)
  {
    if (color_statusbar_ccc)
    {
      activate_status_buttons_ccc();
      if (connected_ccc)
      {
        gdk_rgba_parse(&button_color_ccc, GTKCOLOR_LIME);
        if (ata_status_ccc & 0x80)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_bsy_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x40)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_drdy_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x20)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_df_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x10)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_dsc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x08)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_drq_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x04)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_corr_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x02)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_idx_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_status_ccc & 0x01)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_err_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }

        gdk_rgba_parse(&button_color_ccc, GTKCOLOR_RED);
        if (ata_error_ccc & 0x80)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_bbk_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x40)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_unc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x20)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_mc_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x10)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_idnf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x08)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_mcr_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x04)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_abrt_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x02)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_tk0nf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (ata_error_ccc & 0x01)
        {
          gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
          gtk_widget_override_background_color(GTK_WIDGET(button_amnf_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
        }
        if (color_switch_flag_ccc == 0)
        {
          color_switch_flag_ccc = 1;
          gdk_rgba_parse(&button_color_ccc, "#000");
        }
        else if (color_switch_flag_ccc == 1)
        {
          color_switch_flag_ccc = 2;
          gdk_rgba_parse(&button_color_ccc, "#777");
        }
        else
        {
          color_switch_flag_ccc = 0;
          gdk_rgba_parse(&button_color_ccc, "#fff");
        }
        gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_NORMAL, &button_color_ccc);
        gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_PRELIGHT, &button_color_ccc);
        gtk_widget_override_background_color(GTK_WIDGET(button_status_separator_ccc), GTK_STATE_FLAG_ACTIVE, &button_color_ccc);
      }
    }
    else
    {
      deactivate_status_buttons_ccc();
      if (connected_ccc)
      {
        if (ata_status_ccc & 0x80)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_bsy_ccc), TRUE);
        }
        if (ata_status_ccc & 0x40)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_drdy_ccc), TRUE);
        }
        if (ata_status_ccc & 0x20)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_df_ccc), TRUE);
        }
        if (ata_status_ccc & 0x10)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_dsc_ccc), TRUE);
        }
        if (ata_status_ccc & 0x08)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_drq_ccc), TRUE);
        }
        if (ata_status_ccc & 0x04)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_corr_ccc), TRUE);
        }
        if (ata_status_ccc & 0x02)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_idx_ccc), TRUE);
        }
        if (ata_status_ccc & 0x01)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_err_ccc), TRUE);
        }

        if (ata_error_ccc & 0x80)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_bbk_ccc), TRUE);
        }
        if (ata_error_ccc & 0x40)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_unc_ccc), TRUE);
        }
        if (ata_error_ccc & 0x20)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_mc_ccc), TRUE);
        }
        if (ata_error_ccc & 0x10)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_idnf_ccc), TRUE);
        }
        if (ata_error_ccc & 0x08)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_mcr_ccc), TRUE);
        }
        if (ata_error_ccc & 0x04)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_abrt_ccc), TRUE);
        }
        if (ata_error_ccc & 0x02)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_tk0nf_ccc), TRUE);
        }
        if (ata_error_ccc & 0x01)
        {
          gtk_widget_set_sensitive(GTK_WIDGET(button_amnf_ccc), TRUE);
        }
        if (color_switch_flag_ccc == 0)
        {
          color_switch_flag_ccc = 1;
          gtk_widget_set_sensitive(GTK_WIDGET(button_status_separator_ccc), TRUE);
          gtk_button_set_label(GTK_BUTTON(button_status_separator_ccc), "\\");
        }
        else if (color_switch_flag_ccc == 1)
        {
          color_switch_flag_ccc = 2;
          gtk_widget_set_sensitive(GTK_WIDGET(button_status_separator_ccc), FALSE);
          gtk_button_set_label(GTK_BUTTON(button_status_separator_ccc), "|");
        }
        else
        {
          color_switch_flag_ccc = 0;
          gtk_widget_set_sensitive(GTK_WIDGET(button_status_separator_ccc), TRUE);
          gtk_button_set_label(GTK_BUTTON(button_status_separator_ccc), "/");
        }
      }
    }
  }
}

void update_mode_ccc(void)
{
  if (generic_mode_ccc || scsi_passthrough_ccc || nvme_passthrough_ccc || fill_mode_ccc)
  {
    deactivate_status_buttons_ccc();
  }
  else
  {
    activate_status_buttons_ccc();
  }
  if (fill_mode_ccc)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(sourcemi_ccc), FALSE);
  }
  else
  {
    gtk_widget_set_sensitive(GTK_WIDGET(sourcemi_ccc), TRUE);
  }
  update_display_ccc(0);
}

void update_clone_button_settings_ccc(void)
{
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(phase1_check_button_ccc), !clone_settings_ccc.no_phase1);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(phase2_check_button_ccc), !clone_settings_ccc.no_phase2);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(phase3_check_button_ccc), !clone_settings_ccc.no_phase3);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(phase4_check_button_ccc), !clone_settings_ccc.no_phase4);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(divide_check_button_ccc), !clone_settings_ccc.no_divide1);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(divide2_check_button_ccc), clone_settings_ccc.do_divide2);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(trim_check_button_ccc), !clone_settings_ccc.no_trim);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(scrape_check_button_ccc), !clone_settings_ccc.no_scrape);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(markbad_check_button_ccc), clone_settings_ccc.mark_bad_head);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(readbad_check_button_ccc), clone_settings_ccc.read_bad_head);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(rebuild_assist_check_button_ccc), clone_settings_ccc.rebuild_assist);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(reverse_check_button_ccc), clone_settings_ccc.reverse);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(skipfast_check_button_ccc), clone_settings_ccc.skip_fast);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, MAX_RETRIES, 1, 1, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(retries_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(retries_spin_button_ccc), clone_settings_ccc.retries);

  int cluster_limit = MAX_CLUSTERSIZE;
  if (source_chosen_ccc)
  {
    cluster_limit = check_buffer_limit_ccc();
    if (cluster_limit < 0)
    {
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    }
    if (clone_settings_ccc.cluster_size > cluster_limit)
    {
      clone_settings_ccc.cluster_size = cluster_limit;
    }
  }
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 1, cluster_limit, 8, 64, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(clustersize_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(clustersize_spin_button_ccc), clone_settings_ccc.cluster_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(inputoffset_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(inputoffset_spin_button_ccc), clone_settings_ccc.input_offset);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(size_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(size_spin_button_ccc), clone_settings_ccc.read_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 1, MAX_BLOCKSIZE, 1, 8, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(blocksize_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(blocksize_spin_button_ccc), clone_settings_ccc.block_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(skipsize_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(skipsize_spin_button_ccc), clone_settings_ccc.min_skip_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(maxskipsize_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(maxskipsize_spin_button_ccc), clone_settings_ccc.max_skip_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 300000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(skipthreshold_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(skipthreshold_spin_button_ccc), clone_settings_ccc.skip_timeout / 1000);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 1000000, 10, 1000, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(rateskip_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(rateskip_spin_button_ccc), clone_settings_ccc.rate_skip / 1000);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 1000000, 10, 1000, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(exitonslow_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(exitonslow_spin_button_ccc), clone_settings_ccc.exit_on_slow / 1000);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 300, 1, 10, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(exitonslowtime_spin_button_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(exitonslowtime_spin_button_ccc), clone_settings_ccc.exit_slow_time / 1000);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, MIN_SECTORSIZE, MAX_SECTORSIZE, 8, 64, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(sectorsize_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(sectorsize_spinbutton_ccc), clone_settings_ccc.sector_size);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, MAX_BLOCKSIZE, 1, 8, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(alignment_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(alignment_spinbutton_ccc), clone_settings_ccc.block_offset);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 10000000, 100, 1000, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(maxreadrate_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(maxreadrate_spinbutton_ccc), clone_settings_ccc.max_read_rate / 1000);

  // gtk_adjustment_ccc = (GtkAdjustment *) gtk_adjustment_new (0, 1, 1, 1, 1, 0);
  // gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(), gtk_adjustment_ccc);
  // gtk_spin_button_set_value(GTK_SPIN_BUTTON(), clone_settings_ccc.);
}

void update_advanced_button_settings_ccc(void)
{
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(force_mounted_checkbutton_ccc), advanced_settings_ccc.force_mounted);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(force_dangerous_checkbutton_ccc), advanced_settings_ccc.force_dangerous);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(no_log_backup_checkbutton_ccc), advanced_settings_ccc.no_log_backup);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_output_offset_checkbutton_ccc), advanced_settings_ccc.enable_output_offset);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_current_position_checkbutton_ccc), advanced_settings_ccc.enable_current_position);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_on_error_radio_button_ccc), advanced_settings_ccc.stop_on_error);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(call_command_radio_button_ccc), advanced_settings_ccc.call_command);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(primary_relay_on_error_radio_button_ccc), advanced_settings_ccc.activate_primary_relay);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(write_buffer_disable_radio_button_ccc), advanced_settings_ccc.write_buffer_disable);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(write_buffer_enable_radio_button_ccc), advanced_settings_ccc.write_buffer_enable);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(driver_return_error_radio_button_ccc), advanced_settings_ccc.driver_return_error);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(driver_return_zeros_radio_button_ccc), advanced_settings_ccc.driver_return_zeros);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(driver_return_marked_radio_button_ccc), advanced_settings_ccc.driver_return_marked);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(disable_identify_checkbutton_ccc), advanced_settings_ccc.disable_identify);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(pio_mode_checkbutton_ccc), advanced_settings_ccc.pio_mode);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_rebuild_assist_checkbutton_ccc), advanced_settings_ccc.enable_rebuild_assist);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_process_chunk_checkbutton_ccc), advanced_settings_ccc.enable_process_chunk);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_read_twice_checkbutton_ccc), advanced_settings_ccc.enable_read_twice);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_retry_connecting_checkbutton_ccc), advanced_settings_ccc.enable_retry_connecting);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_scsi_write_checkbutton_ccc), advanced_settings_ccc.enable_scsi_write);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_phase_log_checkbutton_ccc), advanced_settings_ccc.enable_phase_log);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_output_sector_size_checkbutton_ccc), advanced_settings_ccc.enable_output_sector_size);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(driver_io_scsi_only_checkbutton_ccc), advanced_settings_ccc.driver_io_scsi_only);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(use_physical_sector_size_for_virtual_checkbutton_ccc), advanced_settings_ccc.use_physical_sector_size_for_virtual);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(use_color_statusbar_checkbutton_ccc), advanced_settings_ccc.color_statusbar);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(output_offset_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(output_offset_spinbutton_ccc), advanced_settings_ccc.output_offset);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -1, 0x7fffffffffffffff, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(current_position_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(current_position_spinbutton_ccc), advanced_settings_ccc.current_position);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, -128, 128, 8, 64, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(output_sector_size_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(output_sector_size_spinbutton_ccc), advanced_settings_ccc.output_sector_adjustment);

  int cluster_limit = MAX_CLUSTERSIZE;
  if (source_chosen_ccc)
  {
    cluster_limit = check_buffer_limit_ccc();
    if (cluster_limit < 0)
    {
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    }
  }
  if (clone_settings_ccc.cluster_size > 0 && cluster_limit > clone_settings_ccc.cluster_size)
  {
    cluster_limit = clone_settings_ccc.cluster_size;
  }
  if (advanced_settings_ccc.driver_minimum_cluster_size > cluster_limit)
  {
    advanced_settings_ccc.driver_minimum_cluster_size = cluster_limit;
  }
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 1, cluster_limit, 8, 64, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(driver_minimum_cluster_size_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(driver_minimum_cluster_size_spinbutton_ccc), advanced_settings_ccc.driver_minimum_cluster_size);

  // gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (), advanced_settings_ccc. );

  // gtk_adjustment_ccc = (GtkAdjustment *) gtk_adjustment_new (0, 1, 1, 1, 1, 0);
  // gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(), gtk_adjustment_ccc);
  // gtk_spin_button_set_value(GTK_SPIN_BUTTON(), advanced_settings_ccc.);
}

void update_timer_button_settings_ccc(void)
{
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(stop_on_power_cycle_radio_button_ccc), timer_settings_ccc.stop_on_power_cycle);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(call_power_command_radio_button_ccc), timer_settings_ccc.call_power_command);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(primary_relay_power_cycle_radio_button_ccc), timer_settings_ccc.power_cycle_primary_relay);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 500, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(initial_busy_wait_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(initial_busy_wait_time_spinbutton_ccc), (timer_settings_ccc.initial_busy_wait_time));
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 5000, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(busy_wait_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(busy_wait_time_spinbutton_ccc), timer_settings_ccc.busy_wait_time);
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 500, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(soft_reset_time_spinbutton_ccc), timer_settings_ccc.soft_reset_time);
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(hard_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(hard_reset_time_spinbutton_ccc), timer_settings_ccc.hard_reset_time);
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 0, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(power_cycle_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(power_cycle_time_spinbutton_ccc), timer_settings_ccc.power_cycle_time);
  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 10000, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(general_timeout_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(general_timeout_spinbutton_ccc), timer_settings_ccc.general_timeout);

  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(phase_timers_checkbutton_ccc), timer_settings_ccc.phase_timers);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(p12_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(p12_soft_reset_time_spinbutton_ccc), timer_settings_ccc.p12_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(p3_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(p3_soft_reset_time_spinbutton_ccc), timer_settings_ccc.p3_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(p4_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(p4_soft_reset_time_spinbutton_ccc), timer_settings_ccc.p4_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(td_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(td_soft_reset_time_spinbutton_ccc), timer_settings_ccc.td_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(d2_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(d2_soft_reset_time_spinbutton_ccc), timer_settings_ccc.d2_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(sc_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(sc_soft_reset_time_spinbutton_ccc), timer_settings_ccc.sc_soft_reset_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 50, 900000, 1, 100, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(rt_soft_reset_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(rt_soft_reset_time_spinbutton_ccc), timer_settings_ccc.rt_soft_reset_time);

  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(always_wait_for_reset_timers_checkbutton_ccc), timer_settings_ccc.always_wait_for_reset_timers);

  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_usb_bulk_reset_checkbutton_ccc), timer_settings_ccc.usb_bulk_reset_enabled);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_usb_soft_reset_checkbutton_ccc), timer_settings_ccc.usb_soft_reset_enabled);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_usb_hard_reset_checkbutton_ccc), timer_settings_ccc.usb_hard_reset_enabled);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(enable_usb_port_reset_checkbutton_ccc), timer_settings_ccc.usb_port_reset_enabled);

  // gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (), timer_settings_ccc. );

  // gtk_adjustment_ccc = (GtkAdjustment *) gtk_adjustment_new (0, 1, 1, 1, 1, 0);
  // gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(), gtk_adjustment_ccc);
  // gtk_spin_button_set_value(GTK_SPIN_BUTTON(), timer_settings_ccc.);
}

void update_primary_relay_button_settings_ccc(void)
{
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay1_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay1);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay2_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay2);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay3_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay3);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay4_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay4);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay5_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay5);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay6_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay6);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay7_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay7);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(activate_primary_relay8_checkbutton_ccc), primary_relay_settings_ccc.activate_primary_relay8);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay1_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay1);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay2_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay2);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay3_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay3);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay4_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay4);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay5_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay5);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay6_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay6);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay7_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay7);
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(deactivate_primary_relay8_checkbutton_ccc), primary_relay_settings_ccc.deactivate_primary_relay8);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 1, 900, 1, 1, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(primary_relay_energize_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(primary_relay_energize_time_spinbutton_ccc), primary_relay_settings_ccc.primary_relay_activation_time);

  gtk_adjustment_ccc = (GtkAdjustment *)gtk_adjustment_new(0, 1, 900, 1, 1, 0);
  gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(primary_relay_delay_time_spinbutton_ccc), gtk_adjustment_ccc);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(primary_relay_delay_time_spinbutton_ccc), primary_relay_settings_ccc.primary_relay_delay_time);

  // gtk_toggle_button_set_active( GTK_TOGGLE_BUTTON (), primary_relay_settings_ccc. );

  // gtk_adjustment_ccc = (GtkAdjustment *) gtk_adjustment_new (0, 1, 1, 1, 1, 0);
  // gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(), gtk_adjustment_ccc);
  // gtk_spin_button_set_value(GTK_SPIN_BUTTON(), primary_relay_settings_ccc.);
}

void set_agressive_driver_status_from_button_ccc(void)
{
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(agressive_driver_checkbutton_ccc)))
  {
    aggressive_driver_ccc = TRUE;
    // fprintf (stdout, "agressive mode on\n");    //debug
  }
  else
  {
    aggressive_driver_ccc = FALSE;
    // fprintf (stdout, "agressive mode off\n");    //debug
  }
}

void set_state_from_button_ccc(GtkWidget *widget, gpointer data)
{
  int data_pointer = GPOINTER_TO_INT(data);
  bool button_status;
  bool previous_status;
  if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
  {
    button_status = TRUE;
  }
  else
  {
    button_status = FALSE;
  }
  // g_print ("status=%d, pointer=%d\n", button_status, data_pointer );

  switch (data_pointer)
  {
  case BUTTONID_PHASE1:
    // g_print ("phase1=%d\n", button_status);
    clone_settings_ccc.no_phase1 = !button_status;
    break;

  case BUTTONID_PHASE2:
    // g_print ("phase2=%d\n", button_status);
    clone_settings_ccc.no_phase2 = !button_status;
    break;

  case BUTTONID_PHASE3:
    // g_print ("phase3=%d\n", button_status);
    clone_settings_ccc.no_phase3 = !button_status;
    break;

  case BUTTONID_PHASE4:
    // g_print ("phase4=%d\n", button_status);
    clone_settings_ccc.no_phase4 = !button_status;
    break;

  case BUTTONID_DIVIDE:
    // g_print ("divide=%d\n", button_status);
    clone_settings_ccc.no_divide1 = !button_status;
    break;

  case BUTTONID_DIVIDE2:
    // g_print ("divide2=%d\n", button_status);
    clone_settings_ccc.do_divide2 = button_status;
    break;

  case BUTTONID_TRIM:
    // g_print ("trim=%d\n", button_status);
    clone_settings_ccc.no_trim = !button_status;
    break;

  case BUTTONID_SCRAPE:
    // g_print ("scrape=%d\n", button_status);
    clone_settings_ccc.no_scrape = !button_status;
    break;

  case BUTTONID_MARKBAD:
    // g_print ("badhead=%d\n", button_status);
    clone_settings_ccc.mark_bad_head = button_status;
    break;

  case BUTTONID_READBAD:
    // g_print ("goodhead=%d\n", button_status);
    clone_settings_ccc.read_bad_head = button_status;
    break;

  case BUTTONID_REBUILDASSIST:
    clone_settings_ccc.rebuild_assist = button_status;
    break;

  case BUTTONID_REVERSE:
    // g_print ("reverse=%d\n", button_status);
    clone_settings_ccc.reverse = button_status;
    break;

  case BUTTONID_SKIPFAST:
    // g_print ("skipfast=%d\n", button_status);
    clone_settings_ccc.skip_fast = button_status;
    break;

  case BUTTONID_NOLOGBACK:
    // g_print ("nologback=%d\n", button_status);
    advanced_settings_ccc.no_log_backup = button_status;
    break;

  case BUTTONID_FORCE:
    // g_print ("force=%d\n", button_status);
    advanced_settings_ccc.force_mounted = button_status;
    break;

  case BUTTONID_FORCEDANGEROUS:
    advanced_settings_ccc.force_dangerous = button_status;
    break;

  case BUTTONID_DONTIDENTIFY:
    advanced_settings_ccc.disable_identify = button_status;
    break;

  case BUTTONID_PIOMODE:
    advanced_settings_ccc.pio_mode = button_status;
    break;

  case BUTTONID_ENABLEREBUILDASSIST:
    advanced_settings_ccc.enable_rebuild_assist = button_status;
    break;

  case BUTTONID_ENABLEPROCESSCHUNK:
    advanced_settings_ccc.enable_process_chunk = button_status;
    break;

  case BUTTONID_ENABLEREADTWICE:
    advanced_settings_ccc.enable_read_twice = button_status;
    break;

  case BUTTONID_ENABLERETRYCONNECTING:
    advanced_settings_ccc.enable_retry_connecting = button_status;
    break;

  case BUTTONID_ENABLESCSIWRITE:
    advanced_settings_ccc.enable_scsi_write = button_status;
    break;

  case BUTTONID_ENABLEPHASELOGS:
    advanced_settings_ccc.enable_phase_log = button_status;
    break;

  case BUTTONID_PHASETIMERS:
    // g_print ("phasetimers=%d\n", button_status);
    timer_settings_ccc.phase_timers = button_status;
    break;

  case BUTTONID_OFFSET:
    // g_print ("offset=%d\n", button_status);
    previous_status = advanced_settings_ccc.enable_output_offset;
    advanced_settings_ccc.enable_output_offset = button_status;
    if (previous_status != advanced_settings_ccc.enable_output_offset)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("You must reopen the advanced setting for this change to take effect"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
      clear_error_message_ccc();
    }
    break;

  case BUTTONID_POSITION:
    // g_print ("offset=%d\n", button_status);
    previous_status = advanced_settings_ccc.enable_current_position;
    advanced_settings_ccc.enable_current_position = button_status;
    if (previous_status != advanced_settings_ccc.enable_current_position)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("You must reopen the advanced setting for this change to take effect"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
      clear_error_message_ccc();
    }
    break;

  case BUTTONID_ENABLEOUTPUTSECTOR:
    // g_print ("offset=%d\n", button_status);
    previous_status = advanced_settings_ccc.enable_output_sector_size;
    advanced_settings_ccc.enable_output_sector_size = button_status;
    if (previous_status != advanced_settings_ccc.enable_output_sector_size)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("You must reopen the advanced setting for this change to take effect"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Information"), 0);
      clear_error_message_ccc();
    }
    break;

  case BUTTONID_IOSCSIONLY:
    advanced_settings_ccc.driver_io_scsi_only = button_status;
    break;

  case BUTTONID_USEPHYSICALSECTORSIZE:
    advanced_settings_ccc.use_physical_sector_size_for_virtual = button_status;
    break;

  case BUTTONID_COLORSTATUSBAR:
    advanced_settings_ccc.color_statusbar = button_status;
    break;

  default:
    g_print("Unknown button %d", data_pointer);
    break;
  }
}

void do_reset_status_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  GtkWidget *new_dialog_window;
  new_dialog_window = gtk_dialog_new_with_buttons(_("Reset Current Status"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
  // gtk_widget_set_size_request (new_dialog_window, 400, 200);

  GtkWidget *new_label = gtk_label_new(_("This will reset the current log status to Phase1,\n and current position to 0,\n and reset all skip data"));
  // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(new_dialog_window)->vbox), new_label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(new_dialog_window))), new_label, TRUE, TRUE, 0);

  gtk_widget_show_all(new_dialog_window);
  gint result = gtk_dialog_run(GTK_DIALOG(new_dialog_window));
  gtk_widget_destroy(new_dialog_window);

  if (result == GTK_RESPONSE_ACCEPT)
  {
    g_print("resetting status\n");
    reset_current_status_ccc();
    logfile_changed_ccc = true;
    update_display_ccc(0);
  }
}

void do_reset_log_status_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  GtkWidget *new_dialog_window;
  new_dialog_window = gtk_dialog_new_with_buttons(_("Reset Log"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
  // gtk_widget_set_size_request (new_dialog_window, 400, 200);

  GtkWidget *new_label = gtk_label_new(_("This will reset the position to 0, \nthe current status to non-tried, \nand will change all unfinished blocks \nin the log to a status of non-tried. \nThis will also reset all skipping data."));
  // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(new_dialog_window)->vbox), new_label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(new_dialog_window))), new_label, TRUE, TRUE, 0);

  gtk_widget_show_all(new_dialog_window);
  gint result = gtk_dialog_run(GTK_DIALOG(new_dialog_window));
  gtk_widget_destroy(new_dialog_window);

  if (result == GTK_RESPONSE_ACCEPT)
  {
    g_print("resetting log\n");
    reset_log_status_ccc();
    update_display_ccc(0);
    // check log and if same status found then repair it
    if (source_chosen_ccc)
    {
      check_log_size_ccc = 1;
    }
    else
    {
      check_log_size_ccc = 0;
    }
    repair_log_ccc = true;
    int ret = check_log_ccc();
    clear_error_message_ccc();
    if (ret == 0x10)
    {
      check_and_repair_log_ccc();
    }
    repair_log_ccc = false;
    logfile_changed_ccc = true;
    update_display_ccc(0);
  }
}

void do_repair_log_ccc(void)
{
  if (!project_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("You must choose a project first."));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  GtkWidget *new_dialog_window;
  new_dialog_window = gtk_dialog_new_with_buttons(_("Repair Log"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
  // gtk_widget_set_size_request (new_dialog_window, 400, 200);

  GtkWidget *new_label = gtk_label_new(_("This will repair the current progress log in memory. \nIt is recommended to make a backup copy of the log before repairing."));
  // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(new_dialog_window)->vbox), new_label, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(new_dialog_window))), new_label, TRUE, TRUE, 0);

  gtk_widget_show_all(new_dialog_window);
  gint result = gtk_dialog_run(GTK_DIALOG(new_dialog_window));
  gtk_widget_destroy(new_dialog_window);

  if (result == GTK_RESPONSE_ACCEPT)
  {
    g_print("repairing log\n");
    if (source_chosen_ccc)
    {
      check_log_size_ccc = 1;
    }
    else
    {
      check_log_size_ccc = 0;
    }
    repair_log_ccc = true;
    int ret = check_and_repair_log_ccc();
    if (check_log_ccc() || ret)
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("The log file has errors!\nThe log file will need to be repaired before it can be used.\nPlease reference console messages for more information.\n"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
    repair_log_ccc = false;
    check_log_size_ccc = 1;
    logfile_changed_ccc = true;
    update_display_ccc(0);
  }
}

void about_ccc(void)
{
  GtkWidget *dialog = gtk_about_dialog_new();
  char temp[1024];

  gtk_window_set_title(GTK_WINDOW(dialog), _("About OpenSuperClone"));

  gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), title_ccc);

  snprintf(temp, sizeof(temp), "%s %s", version_number_ccc, GIT_REVISION);
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), temp);

  snprintf(temp, sizeof(temp), _("Copyright (C) %s Scott Dwyer and OpenSuperClone contributors"), copyright_year_ccc);
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), temp);

  snprintf(temp, sizeof(temp), _("License type: GPL2\nThere is NO WARRANTY, to the extent permitted by law."));
  gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), temp);

  gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog), OSC_HOMEPAGE);
  gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), OSC_HOMEPAGE);

  gtk_dialog_run(GTK_DIALOG(dialog));
  gtk_widget_destroy(dialog);
}

// open choose usb dialog window
void choose_primary_usb_ccc(void)
{
  find_all_usb_devices_ccc();

  choose_usb_dialog_window_ccc = gtk_dialog_new_with_buttons(_("Choose USB Relay"), GTK_WINDOW(main_window_ccc), GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL, GTK_STOCK_OK, GTK_RESPONSE_ACCEPT, GTK_STOCK_CANCEL, GTK_RESPONSE_REJECT, NULL);
  gtk_container_set_border_width(GTK_CONTAINER(choose_usb_dialog_window_ccc), 0);
  gtk_widget_set_size_request(choose_usb_dialog_window_ccc, 600, 400);

  choose_usb_scrolled_window_ccc = gtk_scrolled_window_new(NULL, NULL);
  gtk_container_set_border_width(GTK_CONTAINER(choose_usb_scrolled_window_ccc), 10);
  gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(choose_usb_scrolled_window_ccc), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  // gtk_box_pack_start (GTK_BOX (GTK_DIALOG(choose_usb_dialog_window_ccc)->vbox), choose_usb_scrolled_window_ccc, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(choose_usb_dialog_window_ccc))), choose_usb_scrolled_window_ccc, TRUE, TRUE, 0);

  choose_usb_vbox_ccc = gtk_vbox_new(FALSE, 0);
  gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(choose_usb_scrolled_window_ccc), choose_usb_vbox_ccc);

  GtkWidget *button[MAX_USB_DEVICES];

  int i;
  for (i = 0; i < usb_device_count_ccc; i++)
  {
    if (usb_known_relay_ccc[i])
    {
      char button_label[MAX_BUTTON_LABEL_SIZE] = "";
      snprintf(button_label, MAX_BUTTON_LABEL_SIZE, "%04x:%04x %s %s %s\n", usb_vendor_id_ccc[i], usb_product_id_ccc[i], usb_vendor_string_ccc[i], usb_product_string_ccc[i], usb_extra_id_string_ccc[i]);
      button[i] = gtk_button_new_with_label(button_label);
      gtk_button_set_alignment(GTK_BUTTON(button[i]), 0, .5);
      g_signal_connect(button[i], "clicked", G_CALLBACK(get_usb_from_button_ccc), GINT_TO_POINTER(i));
      gtk_box_pack_start(GTK_BOX(choose_usb_vbox_ccc), button[i], FALSE, FALSE, 0);
    }
  }

  gtk_widget_show_all(choose_usb_dialog_window_ccc);
  gint result = gtk_dialog_run(GTK_DIALOG(choose_usb_dialog_window_ccc));
  gtk_widget_destroy(choose_usb_dialog_window_ccc);

  if (result == GTK_RESPONSE_ACCEPT)
  {
    // fprintf (stdout, "OK\n");
    int ret = choose_usb_relay_ccc();
    if (ret)
    {
      fprintf(stdout, "error selecting usb, ret=%d\n", ret);
      clear_usbr1_ccc();
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "%s", _("Error choosing USB relay"));
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
    else
    {
      usbr1_chosen_ccc = 1;
      logfile_changed_ccc = true;
      char name[MAX_RELAY_NAME_LENGTH];
      snprintf(name, MAX_RELAY_NAME_LENGTH, "%04x:%04x %s %s %s\n", usbr1_vendor_id_ccc, usbr1_product_id_ccc, usbr1_vendor_string_ccc, usbr1_product_string_ccc, usbr1_extra_id_string_ccc);
      strcpy(primary_relay_settings_ccc.primary_relay_name, name);
      strcpy(primary_relay_name_ccc, name);
    }
    update_display_ccc(0);
  }
}

void get_usb_from_button_ccc(GtkWidget *w, gpointer data)
{
  new_usb_ccc = GPOINTER_TO_INT(data);
  g_print("selection=%d  \n", new_usb_ccc);
}

void clear_usbr1_ccc(void)
{
  usbr1_chosen_ccc = 0;
  primary_relay_settings_ccc.primary_relay_name[0] = '\0';
  primary_relay_name_ccc[0] = '\0';
  gtk_label_set_text(GTK_LABEL(data_current_relay_board_a_ccc), "");
}

void do_activate_primary_relay_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  bool activate_primary_relay1_bak = primary_relay_settings_ccc.activate_primary_relay1;
  bool activate_primary_relay2_bak = primary_relay_settings_ccc.activate_primary_relay2;
  bool activate_primary_relay3_bak = primary_relay_settings_ccc.activate_primary_relay3;
  bool activate_primary_relay4_bak = primary_relay_settings_ccc.activate_primary_relay4;
  bool activate_primary_relay5_bak = primary_relay_settings_ccc.activate_primary_relay5;
  bool activate_primary_relay6_bak = primary_relay_settings_ccc.activate_primary_relay6;
  bool activate_primary_relay7_bak = primary_relay_settings_ccc.activate_primary_relay7;
  bool activate_primary_relay8_bak = primary_relay_settings_ccc.activate_primary_relay8;
  bool deactivate_primary_relay1_bak = primary_relay_settings_ccc.deactivate_primary_relay1;
  bool deactivate_primary_relay2_bak = primary_relay_settings_ccc.deactivate_primary_relay2;
  bool deactivate_primary_relay3_bak = primary_relay_settings_ccc.deactivate_primary_relay3;
  bool deactivate_primary_relay4_bak = primary_relay_settings_ccc.deactivate_primary_relay4;
  bool deactivate_primary_relay5_bak = primary_relay_settings_ccc.deactivate_primary_relay5;
  bool deactivate_primary_relay6_bak = primary_relay_settings_ccc.deactivate_primary_relay6;
  bool deactivate_primary_relay7_bak = primary_relay_settings_ccc.deactivate_primary_relay7;
  bool deactivate_primary_relay8_bak = primary_relay_settings_ccc.deactivate_primary_relay8;
  unsigned long long primary_relay_activation_time_bak = primary_relay_settings_ccc.primary_relay_activation_time;
  unsigned long long primary_relay_delay_time_bak = primary_relay_settings_ccc.primary_relay_delay_time;

  update_primary_relay_settings_from_buttons_ccc();
  update_primary_relay_settings_ccc();

  g_print("activate primary relay\n");
  if (activate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }

  primary_relay_settings_ccc.activate_primary_relay1 = activate_primary_relay1_bak;
  primary_relay_settings_ccc.activate_primary_relay2 = activate_primary_relay2_bak;
  primary_relay_settings_ccc.activate_primary_relay3 = activate_primary_relay3_bak;
  primary_relay_settings_ccc.activate_primary_relay4 = activate_primary_relay4_bak;
  primary_relay_settings_ccc.activate_primary_relay5 = activate_primary_relay5_bak;
  primary_relay_settings_ccc.activate_primary_relay6 = activate_primary_relay6_bak;
  primary_relay_settings_ccc.activate_primary_relay7 = activate_primary_relay7_bak;
  primary_relay_settings_ccc.activate_primary_relay8 = activate_primary_relay8_bak;
  primary_relay_settings_ccc.deactivate_primary_relay1 = deactivate_primary_relay1_bak;
  primary_relay_settings_ccc.deactivate_primary_relay2 = deactivate_primary_relay2_bak;
  primary_relay_settings_ccc.deactivate_primary_relay3 = deactivate_primary_relay3_bak;
  primary_relay_settings_ccc.deactivate_primary_relay4 = deactivate_primary_relay4_bak;
  primary_relay_settings_ccc.deactivate_primary_relay5 = deactivate_primary_relay5_bak;
  primary_relay_settings_ccc.deactivate_primary_relay6 = deactivate_primary_relay6_bak;
  primary_relay_settings_ccc.deactivate_primary_relay7 = deactivate_primary_relay7_bak;
  primary_relay_settings_ccc.deactivate_primary_relay8 = deactivate_primary_relay8_bak;
  primary_relay_settings_ccc.primary_relay_activation_time = primary_relay_activation_time_bak;
  primary_relay_settings_ccc.primary_relay_delay_time = primary_relay_delay_time_bak;
  update_primary_relay_settings_ccc();
}

void do_deactivate_primary_relay_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  bool activate_primary_relay1_bak = primary_relay_settings_ccc.activate_primary_relay1;
  bool activate_primary_relay2_bak = primary_relay_settings_ccc.activate_primary_relay2;
  bool activate_primary_relay3_bak = primary_relay_settings_ccc.activate_primary_relay3;
  bool activate_primary_relay4_bak = primary_relay_settings_ccc.activate_primary_relay4;
  bool activate_primary_relay5_bak = primary_relay_settings_ccc.activate_primary_relay5;
  bool activate_primary_relay6_bak = primary_relay_settings_ccc.activate_primary_relay6;
  bool activate_primary_relay7_bak = primary_relay_settings_ccc.activate_primary_relay7;
  bool activate_primary_relay8_bak = primary_relay_settings_ccc.activate_primary_relay8;
  bool deactivate_primary_relay1_bak = primary_relay_settings_ccc.deactivate_primary_relay1;
  bool deactivate_primary_relay2_bak = primary_relay_settings_ccc.deactivate_primary_relay2;
  bool deactivate_primary_relay3_bak = primary_relay_settings_ccc.deactivate_primary_relay3;
  bool deactivate_primary_relay4_bak = primary_relay_settings_ccc.deactivate_primary_relay4;
  bool deactivate_primary_relay5_bak = primary_relay_settings_ccc.deactivate_primary_relay5;
  bool deactivate_primary_relay6_bak = primary_relay_settings_ccc.deactivate_primary_relay6;
  bool deactivate_primary_relay7_bak = primary_relay_settings_ccc.deactivate_primary_relay7;
  bool deactivate_primary_relay8_bak = primary_relay_settings_ccc.deactivate_primary_relay8;
  unsigned long long primary_relay_activation_time_bak = primary_relay_settings_ccc.primary_relay_activation_time;
  unsigned long long primary_relay_delay_time_bak = primary_relay_settings_ccc.primary_relay_delay_time;

  update_primary_relay_settings_from_buttons_ccc();
  update_primary_relay_settings_ccc();

  g_print("deactivate primary relay\n");
  if (deactivate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }

  primary_relay_settings_ccc.activate_primary_relay1 = activate_primary_relay1_bak;
  primary_relay_settings_ccc.activate_primary_relay2 = activate_primary_relay2_bak;
  primary_relay_settings_ccc.activate_primary_relay3 = activate_primary_relay3_bak;
  primary_relay_settings_ccc.activate_primary_relay4 = activate_primary_relay4_bak;
  primary_relay_settings_ccc.activate_primary_relay5 = activate_primary_relay5_bak;
  primary_relay_settings_ccc.activate_primary_relay6 = activate_primary_relay6_bak;
  primary_relay_settings_ccc.activate_primary_relay7 = activate_primary_relay7_bak;
  primary_relay_settings_ccc.activate_primary_relay8 = activate_primary_relay8_bak;
  primary_relay_settings_ccc.deactivate_primary_relay1 = deactivate_primary_relay1_bak;
  primary_relay_settings_ccc.deactivate_primary_relay2 = deactivate_primary_relay2_bak;
  primary_relay_settings_ccc.deactivate_primary_relay3 = deactivate_primary_relay3_bak;
  primary_relay_settings_ccc.deactivate_primary_relay4 = deactivate_primary_relay4_bak;
  primary_relay_settings_ccc.deactivate_primary_relay5 = deactivate_primary_relay5_bak;
  primary_relay_settings_ccc.deactivate_primary_relay6 = deactivate_primary_relay6_bak;
  primary_relay_settings_ccc.deactivate_primary_relay7 = deactivate_primary_relay7_bak;
  primary_relay_settings_ccc.deactivate_primary_relay8 = deactivate_primary_relay8_bak;
  primary_relay_settings_ccc.primary_relay_activation_time = primary_relay_activation_time_bak;
  primary_relay_settings_ccc.primary_relay_delay_time = primary_relay_delay_time_bak;
  update_primary_relay_settings_ccc();
}

void do_activate_primary_relay_main_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  g_print("activate primary relay\n");
  if (activate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
}

void do_deactivate_primary_relay_main_ccc(void)
{
  if (!usbr1_chosen_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error: No relay has been chosen"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
    return;
  }
  g_print("deactivate primary relay\n");
  if (deactivate_primary_relay_ccc())
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, _("Error operating relay, see console for more information"));
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
}

void map_heads_ccc(void)
{
  if (!connected_ccc)
  {
    snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "you must be connected to map heads");
    message_error_ccc(tempmessage_ccc);
    print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
    clear_error_message_ccc();
  }
  else
  {
    if (rebuild_assist_map_heads_ccc())
    {
      snprintf(tempmessage_ccc, TEMP_MESSAGE_SIZE, "error mapping heads");
      message_error_ccc(tempmessage_ccc);
      print_gui_error_message_ccc(error_message_ccc, _("Error!"), 1);
      clear_error_message_ccc();
    }
  }
}
