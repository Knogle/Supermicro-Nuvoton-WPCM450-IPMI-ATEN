
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "smash_clpxml.h"

#define SM_REMOVE_TEMP_FILE

const CMD_USAGE_MSG_TAG cmd_usage_tbl[]={
{"cd","COMMAND OK :\n","Command Name: cd\n\
Used to set the current default target (navigate the target address space of the map)\n\n\
Usage: cd [-options] [target]\n\n\
Options: default - used to go to the root(should not be used with any target)\n\
 	 examine - used to examine the command(bypasses executer)\n\
	 help - shows help on how to use cd\n\
	 keep - not implemented (no impact for now)\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - will wait for the command to be executed\n"},
{"create","COMMAND OK :\n","Command Name: Create\n\
Used to create a new instance and associations in the address space of the MAP.\n\
This is only allowed for specific target object types as defined by the profiles and specific MAP implementation.\n\n\
Usage: create [-options] target [property = value] [property = value]\n\n\
Options:default - not implemented\n\
	 examine - used to examine the command(bypasses executer)\n\
	 help - shows help on how to use Create\n\	 
	 keep - not implemented (no impact for now)\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - will wait for the command to be executed\n"},
{"delete","COMMAND OK :\n","Command Name: Delete\n\
Used to destroy instances in the address space of the MAP.\n\
This is only allowed for specific target object gypes as defined by the profiles and specific MAP implementation\n\n\
Usage: delete [-options] target\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - to delete the target forcefully\n\
	 help - shows help on how to use Delete\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - will wait for the command to be executed\n"},
{"dump","COMMAND OK :\n","Command Name: Dump\n\
Used to take a binary image from an ME and send it to a specific location (specified as a URI).\n\
This command is supported only on certain specific target profiles.\n\n\
Usage: dump -destination <URI> [-options] [target]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - to delete the target forcefully\n\
	 help - shows help on how to use Delete\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - will wait for the command to be executed\n"},
{"exit","COMMAND OK :\n","Command Name: Exit\n\
Used to terminate a CLP session\n\n\
Usage: exit [-options]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 help - shows help on how to use Exit\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n"},
{"help","COMMAND OK :\n","Command Name: Help\n\
Used to request information about the use of CLP \n\n\
Usage: help [-options] [help topics]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 help - shows help on how to use Help\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - Hold the response until all the jobs spawned by this command is finished\n\n\
Help Topics: It`s the CLP command verb say cd,show etc..\n"},
{"load","COMMAND OK :\n","Command Name: Load\n\
Used to take a binary image from specific source location (specified as a URI) and place it at the specified target address.\n\
This command is supported only on certain specific target profiles.\n\n\
Usage: load -source <URI> [-options] [target]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - to delete the target forcefully\n\
	 help - shows help on how to use Delete\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows the smash version\n\
	 wait - will wait for the command to be executed\n"},
{"reset","COMMAND OK :\n","Command Name: Reset\n\
Used to cause a target with power/process control to cycle states from enabled to disabled and back to enabled.\n\n\
Usage: reset [-options] [target]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - forcefully resets the target\n\
	 help - shows help on how to use Reset\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 resetstate - not implemented\n\
	 state - not implemented\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"},
{"set","COMMAND OK :\n","Command Name: Set\n\
Used to set a property or set of properties to specific values.\n\n\
Usage: set [-options] [target] <property name => <value>\n\n\
Example: set \nic1 properties=(IP=a.b.c.d, MASK=255.255.255.0)\n\n\
Options: default - not implemented\n\
	 display - not implemented\n\
	 examine - used to examine the command(bypasses executer)\n\
	 force - Used to Set the target forcefully\n\
	 help - shows help on how to use Set\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"},
{"show","COMMAND OK :\n","Command Name: Show\n\
Used to show values of a property or content of a collection/target.\n\n\
Usage: show [-options] [target] <property name => <value>\n\n\
Example: show -level all \system1\n\n\
Options: all - shows targets upto the maximum level from the current one( should be used with level)	 default - not implemented\n\
	 display - Used to display 'targets' or 'properties' under one or more targets\n\
	 examine - used to examine the command(bypasses executer)\n\
	 force -  not implemented\n\
	 help - shows help on how to use Show\n\
	 keep - not implemented\n\
	 level - Used to show more than one level of output in the target tree\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"},
{"start","COMMAND OK :\n","Command Name: Start\n\
Used to cause a target with power/process control to change states to a higher level.\n\n\
Usage: start [-options] [target]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - Used to start target forcefully\n\
	 help - shows help on how to use Start\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 state - not implemented\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"},
{"stop","COMMAND OK :\n","Command Name: Stop\n\
Used to cause a target with power/process control to change states to a lower run level.\n\n\
Usage: stop [-options] [target]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - Stops target forcefully\n\
	 help -  show help on how to use Stop\n\
	 keep - not implemented\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 state - not implemented\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"},
{"version","COMMAND OK :\n","Command Name: Version\n\
Used to query the version of the CLP implementation (by default) and other CLP elements (when specified).\n\n\
Usage: version [-options]\n\n\
Options:examine - used to examine the command(bypasses executer)\n\
	 force - not implemented\n\
	 help - shows help on how to use Version\n\
	 output - Is there to format the output string( should be used with format(clpcsv,keyword,clpxml)\n\
	 version - shows smash version\n\
	 wait - will wait for the command to be executed\n"}
};

void getDateTime(char *date)
{
	struct tm *t = NULL;
	time_t ltime;

	ltime = time(&ltime);
	t = localtime(&ltime);
	

	sprintf(date,"%04d%02d%02d%02d%02d%02d.000000%c%03d",
	t->tm_year+1900,
	t->tm_mon+1,
	t->tm_mday,
	t->tm_hour,
	t->tm_min,
	t->tm_sec,
	(timezone>0)?'-':'+',
	labs(timezone/60-(t->tm_isdst?60:0)));

}




const SM_CMD_STATUS_TAG_TBL sm_cmd_status_tag_tbl[]={
	{"COMMAND COMPLETED",strlen("COMMAND COMPLETED")},
	{"COMMAND SPAWNED",strlen("COMMAND COMPLETED")},
	{"COMMAND PROCESSING FAILED",strlen("COMMAND PROCESSING FAILED")},
	{"COMMAND EXECUTION FAILED",strlen("COMMAND EXECUTION FAILED")}	
};

const SM_ERROR_TBL sm_err_tbl[]={
	{255,"COMMAND ERROR ¡V UNSPECIFIED",strlen("COMMAND ERROR ¡V UNSPECIFIED")},
	{254,"COMMAND NOT SUPPORTED",strlen("COMMAND NOT SUPPORTED")},
	{253,"COMMAND NOT RECOGNIZED",strlen("COMMAND NOT RECOGNIZED")},
	{252,"COMMAND SYNTAX ERROR",strlen("COMMAND SYNTAX ERROR")},
	{251,"INVALID OPTION",strlen("INVALID OPTION")},
	{250,"INVALID ARGUMENT",strlen("INVALID ARGUMENT")},
	{249,"OUTPUT FORMAT NOT SUPPORTED",strlen("OUTPUT FORMAT NOT SUPPORTED")},
	{248,"MISSING ARGUMENT",strlen("MISSING ARGUMENT")},
	{247,"OPTION NOT SUPPORTED",strlen("OPTION NOT SUPPORTED")},
	{246,"INVALID TARGET",strlen("INVALID TARGET")},
	{245,"REQUIRED OPTION MISSING",strlen("REQUIRED OPTION MISSING")},
	{244,"QUEUE FULL",strlen("QUEUE FULL")},
	{243,"UNRECOGNIZED OEM EXTENSION",strlen("UNRECOGNIZED OEM EXTENSION")},
	{242,"MISSING REQUIRED TARGET",strlen("MISSING REQUIRED TARGET")},
	{241,"FUNCTION NOT SUPPORTED",strlen("FUNCTION NOT SUPPORTED")}
};


const SM_ERROR_TYPE_TBL sm_err_type_tbl[]={
	{"Unknown",strlen("Unknown")},
	{"Other",strlen("Other")},
	{"Communications Error",strlen("Communications Error")},
	{"Quality of Service Error",strlen("Quality of Service Error")},
	{"Software Error",strlen("Software Error")},
	{"Hardware Error",strlen("Hardware Error")},
	{"Environmental Error",strlen("Environmental Error")},
	{"Security Error",strlen("Security Error")},
	{"Oversubscription Error",strlen("Oversubscription Error")},
	{"Unavailable Resource Error",strlen("Unavailable Resource Error")},
	{"Unsupported Operation Error",strlen("Unsupported Operation Error")}
};

const SM_CIM_STATUS_TBL sm_cim_status_tbl[]={
	{1,"CIM_ERR_FAILED",strlen("CIM_ERR_FAILED")},
	{2,"CIM_ERR_ACCESS_DENIED",strlen("CIM_ERR_ACCESS_DENIED")},
	{3,"CIM_ERR_INVALID_NAMESPACE",strlen("CIM_ERR_INVALID_NAMESPACE")},
	{4,"CIM_ERR_INVALID_PARAMETER",strlen("CIM_ERR_INVALID_PARAMETER")},
	{5,"CIM_ERR_INVALID_CLASS",strlen("CIM_ERR_INVALID_CLASS")},
	{6,"CIM_ERR_NOT_FOUND",strlen("CIM_ERR_NOT_FOUND")},
	{7,"CIM_ERR_NOT_SUPPORTED",strlen("CIM_ERR_NOT_SUPPORTED")},
	{8,"CIM_ERR_CLASS_HAS_CHILDREN",strlen("CIM_ERR_CLASS_HAS_CHILDREN")},
	{9,"CIM_ERR_CLASS_HAS_INSTANCES",strlen("CIM_ERR_CLASS_HAS_INSTANCES")},
	{10,"CIM_ERR_INVALID_SUPERCLASS",strlen("CIM_ERR_INVALID_SUPERCLASS")},
	{11,"CIM_ERR_ALREADY_EXISTS",strlen("CIM_ERR_ALREADY_EXISTS")},
	{12,"CIM_ERR_NO_SUCH_PROPERTY",strlen("CIM_ERR_NO_SUCH_PROPERTY")},
	{13,"CIM_ERR_TYPE_MISMATCH",strlen("CIM_ERR_TYPE_MISMATCH")},
	{14,"CIM_ERR_QUERY_LANGUAGE_NOT_SUPPORTED",strlen("CIM_ERR_QUERY_LANGUAGE_NOT_SUPPORTED")},
	{15,"CIM_ERR_INVALID_QUERY",strlen("CIM_ERR_INVALID_QUERY")},
	{16,"CIM_ERR_METHOD_NOT_AVAILABLE",strlen("CIM_ERR_METHOD_NOT_AVAILABLE")},
	{17,"CIM_ERR_METHOD_NOT_FOUND",strlen("CIM_ERR_METHOD_NOT_FOUND")},
	{18,"CIM_ERR_UNEXPECTED_RESPONSE",strlen("CIM_ERR_UNEXPECTED_RESPONSE")},
	{19,"CIM_ERR_INVALID_RESPONSE_DESTINATION",strlen("CIM_ERR_INVALID_RESPONSE_DESTINATION")},
	{20,"CIM_ERR_NAMESPACE_NOT_EMPTY",strlen("CIM_ERR_NAMESPACE_NOT_EMPTY")}
};

const SM_SEVERITY_TBL sm_severity_tbl[]={
	{0,"Unknown",strlen("Unknown")},
	{2,"Low",strlen("Low")},
	{3,"Medium",strlen("Medium")},
	{4,"High",strlen("High")},
	{5,"Fatal",strlen("Fatal")}
};


const SM_PROB_CAUSE_TBL sm_probcause_tbl[]={
	{"Unknown",strlen("Unknown")},
	{"Other",strlen("Other")},
	{"Adapter/Card Error",strlen("Adapter/Card Error")},
	{"Application Subsystem Failure",strlen("Application Subsystem Failure")},
	{"Bandwidth Reduced",strlen("Bandwidth Reduced")},
	{"Connection Establishment Error",strlen("Connection Establishment Error")},
	{"Communications Protocol Error",strlen("Communications Protocol Error")},
	{"Communications Subsystem Failure",strlen("Communications Subsystem Failure")},
	{"Configuration/Customization Error",strlen("Configuration/Customization Error")},
	{"Congestion",strlen("Congestion")},
	{"Corrupt Data",strlen("Corrupt Data")},        
	{"CPU Cycles Limit Exceeded",strlen("CPU Cycles Limit Exceeded")},      
	{"Dataset/Modem Error",strlen("Dataset/Modem Error")},
	{"Degraded Signal",strlen("Degraded Signal")},
	{"DTE-DCE Interface Error",strlen("DTE-DCE Interface Error")},
	{"Enclosure Door Open",strlen("Enclosure Door Open")},
	{"Equipment Malfunction",strlen("Equipment Malfunction")},
	{"Excessive Vibration",strlen("Excessive Vibration")},
	{"File Format Error",strlen("File Format Error")},
	{"Fire Detected",strlen("Fire Detected")},
	{"Flood Detected",strlen("Flood Detected")},
	{"Framing Error",strlen("Framing Error")},
	{"HVAC Problem",strlen("HVAC Problem")},
	{"Humidity Unacceptable",strlen("Humidity Unacceptable")},
	{"I/O Device Error",strlen("I/O Device Error")},
	{"Input Device Error",strlen("Input Device Error")},
	{"LAN Error",strlen("LAN Error")},
	{"Non-Toxic Leak Detected",strlen("Non-Toxic Leak Detected")},
	{"Local Node Transmission Error",strlen("Local Node Transmission Error")},
	{"Loss of Frame",strlen("Loss of Frame")},
	{"Loss of Signal",strlen("Loss of Signal")},
	{"Material Supply Exhausted",strlen("Material Supply Exhausted")},
	{"Multiplexer Problem",strlen("Multiplexer Problem")},
	{"Out of Memory",strlen("Out of Memory")},
	{"Output Device Error",strlen("Output Device Error")},
	{"Performance Degraded",strlen("Performance Degraded")},
	{"Power Problem",strlen("Power Problem")},
	{"Pressure Unacceptable",strlen("Pressure Unacceptable")},
	{"Processor Problem (Internal Machine Error)",strlen("Processor Problem (Internal Machine Error)")},
	{"Pump Failure",strlen("Pump Failure")},
	{"Queue Size Exceeded",strlen("Queue Size Exceeded")},
	{"Receive Failure",strlen("Receive Failure")},
	{"Receiver Failure",strlen("Receiver Failure")},
	{"Remote Node Transmission Error",strlen("Remote Node Transmission Error")},
	{"Resource at or Nearing Capacity",strlen("Resource at or Nearing Capacity")},
	{"Response Time Excessive",strlen("Response Time Excessive")},
	{"Retransmission Rate Excessive",strlen("Retransmission Rate Excessive")},
	{"Software Error",strlen("Software Error")},
	{"Software Program Abnormally Terminated",strlen("Software Program Abnormally Terminated")},
	{"Software Program Error (Incorrect Results)",strlen("Software Program Error (Incorrect Results)")},
	{"Storage Capacity Problem",strlen("Storage Capacity Problem")},
	{"Temperature Unacceptable",strlen("Temperature Unacceptable")},
	{"Threshold Crossed",strlen("Threshold Crossed")},
	{"Timing Problem",strlen("Timing Problem")},
	{"Toxic Leak Detected",strlen("Toxic Leak Detected")},
	{"Transmit Failure",strlen("Transmit Failure")},
	{"Transmitter Failure",strlen("Transmitter Failure")},
	{"Underlying Resource Unavailable",strlen("Underlying Resource Unavailable")},
	{"Version Mismatch",strlen("Version Mismatch")},
	{"Previous Alert Cleared",strlen("Previous Alert Cleared")},
	{"Login Attempts Failed",strlen("Login Attempts Failed")},
	{"Software Virus Detected",strlen("Software Virus Detected")},
	{"Hardware Security Breached",strlen("Hardware Security Breached")},
	{"Denial of Service Detected",strlen("Denial of Service Detected")},
	{"Security Credential Mismatch",strlen("Security Credential Mismatch")},
	{"Unauthorized Access",strlen("Unauthorized Access")},
	{"Alarm Received",strlen("Alarm Received")},
	{"Loss of Pointer",strlen("Loss of Pointer")},
	{"Payload Mismatch",strlen("Payload Mismatch")},
	{"Transmission Error",strlen("Transmission Error")},
	{"Excessive Error Rate",strlen("Excessive Error Rate")},
	{"Trace Problem",strlen("Trace Problem")},
	{"Element Unavailable",strlen("Element Unavailable")},
	{"Element Missing",strlen("Element Missing")},
	{"Loss of Multi Frame",strlen("Loss of Multi Frame")},
	{"Broadcast Channel Failure",strlen("Broadcast Channel Failure")},
	{"Invalid Message Received",strlen("Invalid Message Received")},
	{"Routing Failure",strlen("Routing Failure")},
	{"Backplane Failure",strlen("Backplane Failure")},
	{"Identifier Duplication",strlen("Identifier Duplication")},
	{"Protection Path Failure",strlen("Protection Path Failure")},
	{"Sync Loss or Mismatch",strlen("Sync Loss or Mismatch")},
	{"Terminal Problem",strlen("Terminal Problem")},
	{"Real Time Clock Failure",strlen("Real Time Clock Failure")},
	{"Antenna Failure",strlen("Antenna Failure")},
	{"Battery Charging Failure",strlen("Battery Charging Failure")},
	{"Disk Failure",strlen("Disk Failure")},
	{"Frequency Hopping Failure",strlen("Frequency Hopping Failure")},
	{"Loss of Redundancy",strlen("Loss of Redundancy")},
	{"Power Supply Failure",strlen("Power Supply Failure")},
	{"Signal Quality Problem",strlen("Signal Quality Problem")},
	{"Battery Discharging",strlen("Battery Discharging")},
	{"Battery Failure",strlen("Battery Failure")},
	{"Commercial Power Problem",strlen("Commercial Power Problem")},
	{"Fan Failure",strlen("Fan Failure")},
	{"Engine Failure",strlen("Engine Failure")},
	{"Sensor Failure",strlen("Sensor Failure")},
	{"Fuse Failure",strlen("Fuse Failure")},
	{"Generator Failure",strlen("Generator Failure")},
	{"Low Battery",strlen("Low Battery")},
	{"Low Fuel",strlen("Low Fuel")},
	{"Low Water",strlen("Low Water")},
	{"Explosive Gas",strlen("Explosive Gas")},
	{"High Winds",strlen("High Winds")},
	{"Ice Buildup",strlen("Ice Buildup")},
	{"Smoke",strlen("Smoke")},
	{"Memory Mismatch",strlen("Memory Mismatch")},
	{"Out of CPU Cycles",strlen("Out of CPU Cycles")},
	{"Software Environment Problem",strlen("Software Environment Problem")},
	{"Software Download Failure",strlen("Software Download Failure")},
	{"Element Reinitialized",strlen("Element Reinitialized")},
	{"Timeout",strlen("Timeout")},
	{"Logging Problems",strlen("Logging Problems")},
	{"Leak Detected",strlen("Leak Detected")},
	{"Protection Mechanism Failure",strlen("Protection Mechanism Failure")},
	{"Protecting Resource Failure",strlen("Protecting Resource Failure")},
	{"Database Inconsistency",strlen("Database Inconsistency")},
	{"Authentication Failure",strlen("Authentication Failure")},
	{"Breach of Confidentiality",strlen("Breach of Confidentiality")},
	{"Cable Tamper",strlen("Cable Tamper")},
	{"Delayed Information",strlen("Delayed Information")},
	{"Duplicate Information",strlen("Duplicate Information")},
	{"Information Missing",strlen("Information Missing")},
	{"Information Modification",strlen("Information Modification")},
	{"Information Out of Sequence",strlen("Information Out of Sequence")},
	{"Key Expired",strlen("Key Expired")},
	{"Non-Repudiation Failure",strlen("Non-Repudiation Failure")},
	{"Out of Hours Activity",strlen("Out of Hours Activity")},
	{"Out of Service",strlen("Out of Service")},
	{"Procedural Error",strlen("Procedural Error")},
	{"Unexpected Information",strlen("Unexpected Information")}
};






#if 0
	<dump>
		<help>

		</help>
	</dump>
</response>
#endif

int cmd_help_xml_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf,char *cmd_name)
{
	int tbl_idx=0;
	char *tmp_buf=NULL;
	int rc = -1;
	char *p_cmd = NULL;
	
	
	if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
		rc = append_rsp_msg(rsp_msg_buf,"<cd>\n",strlen("<cd>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
		rc = append_rsp_msg(rsp_msg_buf,"<delete>\n",strlen("<delete>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
		rc = append_rsp_msg(rsp_msg_buf,"<dump>\n",strlen("<dump>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
		rc = append_rsp_msg(rsp_msg_buf,"<exit>\n",strlen("<exit>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
		rc = append_rsp_msg(rsp_msg_buf,"<load>\n",strlen("<load>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
		rc = append_rsp_msg(rsp_msg_buf,"<reset>\n",strlen("<reset>\n"));
		if(rc) return -1;		
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
		rc = append_rsp_msg(rsp_msg_buf,"/set>\n",strlen("<set>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
		rc = append_rsp_msg(rsp_msg_buf,"<show>\n",strlen("<show>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
		rc = append_rsp_msg(rsp_msg_buf,"<start>\n",strlen("<start>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
		rc = append_rsp_msg(rsp_msg_buf,"<stop>\n",strlen("<stop>\n"));
		if(rc) return -1;			
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
		rc = append_rsp_msg(rsp_msg_buf,"<version>\n",strlen("<version>\n"));
		if(rc) return -1;			
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
		rc = append_rsp_msg(rsp_msg_buf,"<create>\n",strlen("<create>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
		rc = append_rsp_msg(rsp_msg_buf,"/oemverb>\n",strlen("<oemverb>\n"));
		if(rc) return -1;
	}else{
		printf("Verb Cannot Found!\n");
		return -1;
	}
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,"<help>\n",strlen("<help>\n"));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_S,strlen(SM_XSD_TEXT_S));
	if(rc) return -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;


	rc = append_rsp_msg(rsp_msg_buf,"\n<![CDATA[\n",strlen("\n<![CDATA[\n"));
	if(rc) return -1;


	
	for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
		if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,cmd_name)){
			if(cmd_usage_tbl[tbl_idx].usage_msg != NULL){
				sprintf(tmp_buf,"%s",cmd_usage_tbl[tbl_idx].usage_msg);
			}
			rc = 0;
			break;
		}
		rc = -1;
	}
	
	if(rc){
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		printf("Error: Cannot find the command help info.!\n");
		return -1;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(tmp_buf) free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,"]]>\n",strlen("]]>\n"));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_E,strlen(SM_XSD_TEXT_E));
	if(rc) return -1;
	
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,"</help>\n",strlen("</help>\n"));
	if(rc) return -1;
	
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	

	if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
		rc = append_rsp_msg(rsp_msg_buf,"</cd>\n",strlen("</cd>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
		rc = append_rsp_msg(rsp_msg_buf,"</delete>\n",strlen("</delete>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
		rc = append_rsp_msg(rsp_msg_buf,"</dump>\n",strlen("</dump>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
		rc = append_rsp_msg(rsp_msg_buf,"</exit>\n",strlen("</exit>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
		rc = append_rsp_msg(rsp_msg_buf,"</load>\n",strlen("</load>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
		rc = append_rsp_msg(rsp_msg_buf,"</reset>\n",strlen("</reset>\n"));
		if(rc) return -1;		
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
		rc = append_rsp_msg(rsp_msg_buf,"</set>\n",strlen("</set>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
		rc = append_rsp_msg(rsp_msg_buf,"</show>\n",strlen("</show>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
		rc = append_rsp_msg(rsp_msg_buf,"</start>\n",strlen("</start>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
		rc = append_rsp_msg(rsp_msg_buf,"</stop>\n",strlen("</stop>\n"));
		if(rc) return -1;			
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
		rc = append_rsp_msg(rsp_msg_buf,"</version>\n",strlen("</version>\n"));
		if(rc) return -1;			
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
		rc = append_rsp_msg(rsp_msg_buf,"</create>\n",strlen("</create>\n"));
		if(rc) return -1;
	}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
		rc = append_rsp_msg(rsp_msg_buf,"/oemverb>\n",strlen("</oemverb>\n"));
		if(rc) return -1;
	}else{
		printf("Verb Cannot Found!\n");
		return -1;
	}
	
	return 0;
}



int sm_dump_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"dump");
		if(rc) return -1;
		return 0;
	}

#if 0
	if( rsp_msg_buf->option & SMASH_OPT_HELP){
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_DUMP_CMD_S,strlen(SM_XSD_DUMP_CMD_S));
			if(rc) return -1;
				
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) return -1;
			
			rc = append_rsp_msg(rsp_msg_buf,"<help>\n",strlen("<help>\n"));
			if(rc) return -1;
				
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_S,strlen(SM_XSD_TEXT_S));
			if(rc) return -1;

			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf == NULL) return -1;


			rc = append_rsp_msg(rsp_msg_buf,"\n<![CDATA[\n",strlen("\n<![CDATA[\n"));
			if(rc) return -1;


			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"dump")){
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL){
						sprintf(tmp_buf,"%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					rc = 0;
					break;
				}
				rc = -1;
			}

			if(rc){
				if(tmp_buf) free(tmp_buf);
				tmp_buf = NULL;
				printf("Error: Cannot find the command help info.!\n");
				return -1;
			}

			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(tmp_buf) free(tmp_buf);
			tmp_buf = NULL;
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,"]]>\n",strlen("]]>\n"));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_E,strlen(SM_XSD_TEXT_E));
			if(rc) return -1;


			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,"</help>\n",strlen("</help>\n"));
			if(rc) return -1;


			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_DUMP_CMD_E,strlen(SM_XSD_DUMP_CMD_E));
			if(rc) return -1;
			
			return 0;
	}
#endif	
	return 0;
}

int sm_delete_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{	
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"delete");
		if(rc) return -1;
		return 0;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_DELETE_CMD_S,strlen(SM_XSD_DELETE_CMD_S));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_S,strlen(SM_XSD_TARGET_S));
	if(rc) return -1;
				
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
	if(rc) return -1;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	if(rsp_msg_buf->inst_num == NULL)
		sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->ufct);
	else
		sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num,
															  rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num);

	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(tmp_buf) free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
	if(rc) return -1;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	sprintf(tmp_buf,"<ufip>%s</ufip>\n",rsp_msg_buf->ufip);
	
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(tmp_buf) free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_E,strlen(SM_XSD_TARGET_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_DELETE_CMD_E,strlen(SM_XSD_DELETE_CMD_E));
	if(rc) return -1;
	
	return 0;
}

int sm_help_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	char *p_cmd = NULL;
	
	if( rsp_msg_buf->option & SMASH_OPT_HELP){	
		if(rsp_msg_buf->cmd_help_msg == NULL)
			p_cmd = rsp_msg_buf->cmd;
		else{
			p_cmd = rsp_msg_buf->cmd_help_msg;
		}
	
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,p_cmd);
		if(rc) return -1;
		return 0;
	}

	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_HELP_CMD_S,strlen(SM_XSD_HELP_CMD_S));
	if(rc) return -1;		

	if(rsp_msg_buf->option && SMASH_OPT_EXAMINE){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_S,strlen(SM_XSD_EXAMINE_S));
		if(rc) return -1;
				
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_S,strlen(SM_XSD_TEXT_S));
		if(rc) return -1;				
						
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->ufip != NULL){
			sprintf(tmp_buf,"If run without the examine option, this command will return help about \"%s.\"",
																rsp_msg_buf->ufip);
		}			

		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) return -1;
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TEXT_E,strlen(SM_XSD_TEXT_E));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_E,strlen(SM_XSD_EXAMINE_E));
		if(rc) return -1;
	}

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_HELP_CMD_E,strlen(SM_XSD_HELP_CMD_E));
	if(rc) return -1;
	
	return 0;
}


int sm_show_level_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	FILE *fp=NULL;
	char *tmp_buf=NULL;
	char *ch_pos=NULL;
	char file_name[64];	
	int rc = -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_S,strlen(SM_XSD_TARGET_S));
	if(rc) return -1;
				
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
	if(rc) return -1;


	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	if(rsp_msg_buf->inst_num == NULL)
		sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->ufct);
	else
		sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num,
															  rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num);

	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(tmp_buf) free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;

	if(rsp_msg_buf->ufip != NULL){
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
	
		sprintf(tmp_buf,"<ufip>%s</ufip>\n",rsp_msg_buf->ufip);

		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
	}


	

	if(rsp_msg_buf->list_property != 0xff){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTIES_S,strlen(SM_XSD_PROPERTIES_S));
		if(rc) return -1;
	
		if(rsp_msg_buf->ppid != 0)
		{
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf != NULL){
				sprintf(file_name,"/tmp/smash_%d",rsp_msg_buf->ppid);
				fp = fopen(file_name,"r");
		
				if(fp != NULL){
					while(fgets(tmp_buf,1024,fp)){
						ch_pos=strchr(tmp_buf,'=');
						if(ch_pos == 0){
							break;
						}				
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTY_S,strlen(SM_XSD_PROPERTY_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_NAME_S,strlen(SM_XSD_NAME_S));
						if(rc) goto read_file_fail;
		    			
		  	  			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,ch_pos-tmp_buf);
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_NAME_E,strlen(SM_XSD_NAME_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALUE_S,strlen(SM_XSD_VALUE_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_8TAB,strlen(SM_XSD_8TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VAL_S,strlen(SM_XSD_VAL_S));
						if(rc) goto read_file_fail;
		    			
		  	  			rc = append_rsp_msg(rsp_msg_buf,ch_pos+1,strlen(ch_pos+1)-1);
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VAL_E,strlen(SM_XSD_VAL_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_8TAB,strlen(SM_XSD_8TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALSTRING_S,strlen(SM_XSD_VALSTRING_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALSTRING_E,strlen(SM_XSD_VALSTRING_E));
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALUE_E,strlen(SM_XSD_VALUE_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTY_E,strlen(SM_XSD_PROPERTY_E));
						if(rc) goto read_file_fail;	
					}
				}
			}
		}
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTIES_E,strlen(SM_XSD_PROPERTIES_E));
		if(rc) return -1;
	}

	if(rsp_msg_buf->support_verbs != -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERBS_S,strlen(SM_XSD_VERBS_S));
		if(rc) return -1;


		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;

		strcat(tmp_buf,"<standardverbs>");
					
		if(rsp_msg_buf->support_verbs & CD_CMD)
			strcat(tmp_buf,"cd ");
		if(rsp_msg_buf->support_verbs & SHOW_CMD)
			strcat(tmp_buf,"show ");
		if(rsp_msg_buf->support_verbs & HELP_CMD)
			strcat(tmp_buf,"help ");
		if(rsp_msg_buf->support_verbs & VERSION_CMD)
			strcat(tmp_buf,"version ");
		if(rsp_msg_buf->support_verbs & EXIT_CMD)
			strcat(tmp_buf,"exit ");
		if(rsp_msg_buf->support_verbs & DELETE_CMD)
			strcat(tmp_buf,"delete ");
		if(rsp_msg_buf->support_verbs & START_CMD)
			strcat(tmp_buf,"start ");
		if(rsp_msg_buf->support_verbs & STOP_CMD)
			strcat(tmp_buf,"stop ");
		if(rsp_msg_buf->support_verbs & RESET_CMD)
			strcat(tmp_buf,"reset ");
		if(rsp_msg_buf->support_verbs & DUMP_CMD)
			strcat(tmp_buf,"dump ");
		if(rsp_msg_buf->support_verbs & SET_CMD)
			strcat(tmp_buf,"set ");
		if(rsp_msg_buf->support_verbs & LOAD_CMD)
			strcat(tmp_buf,"load ");
		if(rsp_msg_buf->support_verbs & CREATE_CMD)
			strcat(tmp_buf,"create ");



		strcat(tmp_buf,"</standardverbs>\n");

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERBS_E,strlen(SM_XSD_VERBS_E));
		if(rc) return -1;
	}



	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_E,strlen(SM_XSD_TARGET_E));
	if(rc) return -1;

	if(fp != NULL){
		fclose(fp);
		#ifdef SM_REMOVE_TEMP_FILE
		sprintf(file_name,"rm -f /tmp/smash_%d",rsp_msg_buf->ppid);
		system(file_name);
		#endif
	}

	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return 0;

read_file_fail:
	if(fp != NULL){
		fclose(fp);
		#ifdef SM_REMOVE_TEMP_FILE
		sprintf(file_name,"rm -f /tmp/smash_%d",rsp_msg_buf->ppid);
		system(file_name);
		#endif
	}

	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return -1;
}


int sm_show_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	FILE *fp=NULL;
	char *tmp_buf=NULL;
	char *ch_pos=NULL;
	char file_name[64];	
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"show");
		if(rc) return -1;
		return 0;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_S,strlen(SM_XSD_SHOW_CMD_S));
	if(rc) return -1;

		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_S,strlen(SM_XSD_TARGET_S));
	if(rc) return -1;
				
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
	if(rc) return -1;




	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	if(rsp_msg_buf->inst_num == NULL)
		sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->ufct);
	else
		sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num,
															  rsp_msg_buf->ufct,
															  rsp_msg_buf->inst_num);

	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(tmp_buf) free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;
	

	if(rsp_msg_buf->list_property != 0xff){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTIES_S,strlen(SM_XSD_PROPERTIES_S));
		if(rc) return -1;
	
		if(rsp_msg_buf->ppid != 0)
		{
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf != NULL){
				sprintf(file_name,"/tmp/smash_%d",rsp_msg_buf->ppid);
				fp = fopen(file_name,"r");
		
				if(fp != NULL){
					while(fgets(tmp_buf,1024,fp)){
						ch_pos=strchr(tmp_buf,'=');
						if(ch_pos == 0){
							break;
						}				
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTY_S,strlen(SM_XSD_PROPERTY_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_NAME_S,strlen(SM_XSD_NAME_S));
						if(rc) goto read_file_fail;
		    			
		  	  			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,ch_pos-tmp_buf);
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_NAME_E,strlen(SM_XSD_NAME_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALUE_S,strlen(SM_XSD_VALUE_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_8TAB,strlen(SM_XSD_8TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VAL_S,strlen(SM_XSD_VAL_S));
						if(rc) goto read_file_fail;
		    			
		  	  			rc = append_rsp_msg(rsp_msg_buf,ch_pos+1,strlen(ch_pos+1)-1);
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VAL_E,strlen(SM_XSD_VAL_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_8TAB,strlen(SM_XSD_8TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALSTRING_S,strlen(SM_XSD_VALSTRING_S));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALSTRING_E,strlen(SM_XSD_VALSTRING_E));
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_7TAB,strlen(SM_XSD_7TAB));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VALUE_E,strlen(SM_XSD_VALUE_E));
						if(rc) goto read_file_fail;
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
						if(rc) goto read_file_fail;
		    			
		    			
						rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTY_E,strlen(SM_XSD_PROPERTY_E));
						if(rc) goto read_file_fail;	
					}
				}
			}
		}
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_PROPERTIES_E,strlen(SM_XSD_PROPERTIES_E));
		if(rc) return -1;
	}

	if(rsp_msg_buf->support_verbs != -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERBS_S,strlen(SM_XSD_VERBS_S));
		if(rc) return -1;


		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;

		strcat(tmp_buf,"<standardverbs>");
					
		if(rsp_msg_buf->support_verbs & CD_CMD)
			strcat(tmp_buf,"cd ");
		if(rsp_msg_buf->support_verbs & SHOW_CMD)
			strcat(tmp_buf,"show ");
		if(rsp_msg_buf->support_verbs & HELP_CMD)
			strcat(tmp_buf,"help ");
		if(rsp_msg_buf->support_verbs & VERSION_CMD)
			strcat(tmp_buf,"version ");
		if(rsp_msg_buf->support_verbs & EXIT_CMD)
			strcat(tmp_buf,"exit ");
		if(rsp_msg_buf->support_verbs & DELETE_CMD)
			strcat(tmp_buf,"delete ");
		if(rsp_msg_buf->support_verbs & START_CMD)
			strcat(tmp_buf,"start ");
		if(rsp_msg_buf->support_verbs & STOP_CMD)
			strcat(tmp_buf,"stop ");
		if(rsp_msg_buf->support_verbs & RESET_CMD)
			strcat(tmp_buf,"reset ");
		if(rsp_msg_buf->support_verbs & DUMP_CMD)
			strcat(tmp_buf,"dump ");
		if(rsp_msg_buf->support_verbs & SET_CMD)
			strcat(tmp_buf,"set ");
		if(rsp_msg_buf->support_verbs & LOAD_CMD)
			strcat(tmp_buf,"load ");
		if(rsp_msg_buf->support_verbs & CREATE_CMD)
			strcat(tmp_buf,"create ");

		strcat(tmp_buf,"</standardverbs>\n");

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_6TAB,strlen(SM_XSD_6TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_5TAB,strlen(SM_XSD_5TAB));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERBS_E,strlen(SM_XSD_VERBS_E));
		if(rc) return -1;
	}




					
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_E,strlen(SM_XSD_TARGET_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_E,strlen(SM_XSD_SHOW_CMD_E));
	if(rc) return -1;

	if(fp != NULL){
		fclose(fp);
		#ifdef SM_REMOVE_TEMP_FILE
 		if(tmp_buf == NULL)
		{
			tmp_buf = (char*)calloc(1024,1);
			memset(tmp_buf, 0, 1024);
		}

		if(tmp_buf != NULL)
		{
			sprintf(tmp_buf,"rm -f %s",file_name);
			system(tmp_buf);
		}
		#endif
	}

	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return 0;

read_file_fail:
	if(fp != NULL){
		fclose(fp);
		#ifdef SM_REMOVE_TEMP_FILE
		sprintf(tmp_buf,"rm -f %s",file_name);
		system(tmp_buf);
		#endif
	}

	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return -1;
}

int sm_cmd_fail(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i  = 0;
	int rc = -1;
	char *tmp_buf = NULL;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBERR_S,strlen(SM_XSD_JOBERR_S));
	if(rc) return -1;




	if(rsp_msg_buf->errtype != -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_ERRTYPE_S,strlen(SM_XSD_ERRTYPE_S));
		if(rc) return -1;
	
		
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"%d",rsp_msg_buf->errtype);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) return -1;	
		free(tmp_buf);
		tmp_buf = NULL;
	
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_ERRTYPE_E,strlen(SM_XSD_ERRTYPE_E));
		if(rc) return -1;
			
			
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
	
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"<errtype_desc>%s</errtype_desc>\n",sm_err_type_tbl[rsp_msg_buf->errtype].err_desc);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) return -1;	
		free(tmp_buf);
		tmp_buf = NULL;
	}

	if(rsp_msg_buf->cimstat != -1){	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CIMSTAT_S,strlen(SM_XSD_CIMSTAT_S));
		if(rc) return -1;
	
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"%d",rsp_msg_buf->cimstat);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) return -1;
		free(tmp_buf);
		tmp_buf = NULL;
	
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CIMSTAT_E,strlen(SM_XSD_CIMSTAT_E));
		if(rc) return -1;
	
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CIMSTATDESC_S,strlen(SM_XSD_CIMSTATDESC_S));
		if(rc) return -1;
	
	
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		
		for(i=0;i<sizeof(sm_cim_status_tbl)/sizeof(SM_CIM_STATUS_TBL);i++){
			if(sm_cim_status_tbl[i].cimstat == rsp_msg_buf->cimstat){
				break;
			}
		}
	
		rc = append_rsp_msg(rsp_msg_buf,sm_cim_status_tbl[i].cimstat_desc,sm_cim_status_tbl[i].str_len);
		if(rc) return -1;
		free(tmp_buf);
		tmp_buf = NULL;
	
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CIMSTATDESC_E,strlen(SM_XSD_CIMSTATDESC_E));
		if(rc) return -1;
	}

	if(rsp_msg_buf->severity != EL_SERVERITY_NO_SETTING){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SERVERITY_S,strlen(SM_XSD_SERVERITY_S));
		if(rc) return -1;
	
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"%d",rsp_msg_buf->severity);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) return -1;
		free(tmp_buf);
		tmp_buf = NULL;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SERVERITY_E,strlen(SM_XSD_SERVERITY_E));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;
				
		for(i=0;i<sizeof(sm_severity_tbl)/sizeof(SM_SEVERITY_TBL);i++){
			if(sm_severity_tbl[i].sev_num == rsp_msg_buf->severity)
				break;
		}
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"<severity_desc>%s</severity_desc>\n",sm_severity_tbl[i].sev_desc);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBERR_E,strlen(SM_XSD_JOBERR_E));
	if(rc) return -1;

	return 0;

}

int sm_start_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	char date[26] = {0};
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"start");
		if(rc) return -1;
		return 0;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_START_CMD_S,strlen(SM_XSD_START_CMD_S));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_S,strlen(SM_XSD_TARGET_S));
	if(rc) return -1;
				
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;

	if(rsp_msg_buf->errtype == -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_4TAB,strlen(SM_XSD_4TAB));
		if(rc) return -1;

		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->inst_num == NULL)
			sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->ufct);
		else
			sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num,
																  rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num);
    	
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
	}
					
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) return -1;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	getDateTime(date);
	sprintf(tmp_buf,"<timestamp>%s</timestamp>\n",date);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	
	free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_TARGET_E,strlen(SM_XSD_TARGET_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_START_CMD_E,strlen(SM_XSD_START_CMD_E));
	if(rc) return -1;


	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return 0;
}

int sm_stop_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"stop");
		if(rc) return -1;
		return 0;
	}


	if(rsp_msg_buf->option == SMASH_OPT_EXAMINE){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_S,strlen(SM_XSD_STOP_CMD_S));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_S,strlen(SM_XSD_EXAMINE_S));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;
			
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->inst_num != NULL)
			sprintf(tmp_buf,"<text>If run without the examine option, this will stop %s%s.</text>\n",rsp_msg_buf->ufct,
																									rsp_msg_buf->inst_num);
		else
			sprintf(tmp_buf,"<text>If run without the examine option, this will stop %s.</text>\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_E,strlen(SM_XSD_EXAMINE_E));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_E,strlen(SM_XSD_STOP_CMD_E));
		if(rc) return -1;
		
		return 0;
	}
		
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_S,strlen(SM_XSD_STOP_CMD_S));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;

	if(rsp_msg_buf->errtype == -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;

		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->inst_num == NULL)
			sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->ufct);
		else
			sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num,
																  rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num);
    	
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
			
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"<ufip>%s</ufip>\n",rsp_msg_buf->ufip);
		
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;		
	}
					
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;

	getDateTime(date);
	sprintf(tmp_buf,"<timestamp>%s</timestamp>\n",date);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	
	free(tmp_buf);
	tmp_buf = NULL;
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_E,strlen(SM_XSD_STOP_CMD_E));
	if(rc) return -1;


	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return 0;
}

int sm_reset_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"reset");
		if(rc) return -1;
		return 0;
	}

#if 0
	if(rsp_msg_buf->option == SMASH_OPT_EXAMINE){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_S,strlen(SM_XSD_STOP_CMD_S));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_S,strlen(SM_XSD_EXAMINE_S));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;
			
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->inst_num != NULL)
			sprintf(tmp_buf,"<text>If run without the examine option, this will stop %s%s.</text>\n",rsp_msg_buf->ufct,
																									rsp_msg_buf->inst_num);
		else
			sprintf(tmp_buf,"<text>If run without the examine option, this will stop %s.</text>\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
			
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_E,strlen(SM_XSD_EXAMINE_E));
		if(rc) return -1;

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STOP_CMD_E,strlen(SM_XSD_STOP_CMD_E));
		if(rc) return -1;
		
		return 0;
	}
#endif		
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_RESET_CMD_S,strlen(SM_XSD_RESET_CMD_S));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_S,strlen(SM_XSD_INSTANCE_S));
	if(rc) return -1;

	if(rsp_msg_buf->errtype == -1){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;

		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		if(rsp_msg_buf->inst_num == NULL)
			sprintf(tmp_buf,"<ufit ufct=\"%s\">%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->ufct);
		else
			sprintf(tmp_buf,"<ufit ufct=\"%s\" instance=\"%s\">%s%s</ufit>\n",rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num,
																  rsp_msg_buf->ufct,
																  rsp_msg_buf->inst_num);
    	
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
			
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"<ufip>%s</ufip>\n",rsp_msg_buf->ufip);
		
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(tmp_buf) free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;		
	}
					
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INSTANCE_E,strlen(SM_XSD_INSTANCE_E));
	if(rc) return -1;

	if(rsp_msg_buf->option && SMASH_OPT_WAIT){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
    	
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		
		getDateTime(date);
		sprintf(tmp_buf,"<timestamp>%s</timestamp>\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) return -1;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_RESET_CMD_E,strlen(SM_XSD_RESET_CMD_E));
	if(rc) return -1;


	if(tmp_buf != NULL){
		free(tmp_buf);
	}
	
	return 0;
}

int sm_version_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"stop");
		if(rc) return -1;
		return 0;
	}

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERSION_CMD_S,strlen(SM_XSD_VERSION_CMD_S));
	if(rc) return -1;


	if(rsp_msg_buf->option && SMASH_OPT_EXAMINE){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_S,strlen(SM_XSD_EXAMINE_S));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
		if(rc) return -1;					
		
		rc = append_rsp_msg(rsp_msg_buf,"<text>If run without the examine option, this will show the SM CLP version.</text>\n"
		     ,strlen("<text>If run without the examine option, this will show the SM CLP version.</text>\n"));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_EXAMINE_E,strlen(SM_XSD_EXAMINE_E));
		if(rc) return -1;		
	}else{		
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
		
		rc = append_rsp_msg(rsp_msg_buf,"<clpversion>v1.0.0</clpversion>\n",strlen("<clpversion>v1.0.0</clpversion>\n"));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
	
		rc = append_rsp_msg(rsp_msg_buf,"<addressingversion>v1.0.0</addressingversion>\n",strlen("<addressingversion>v1.0.0</addressingversion>\n"));
		if(rc) return -1;
	}

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_VERSION_CMD_E,strlen(SM_XSD_VERSION_CMD_E));
	if(rc) return -1;
	
	return 0;
}

int sm_cd_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"cd");
		if(rc) return -1;
		return 0;
	}	
	
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CD_CMD_S,strlen(SM_XSD_CD_CMD_S));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_UFIP_S,strlen(SM_XSD_UFIP_S));
	if(rc) return -1;

		
	if(rsp_msg_buf->ufip != NULL){
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) goto job_fail;
			
		sprintf(tmp_buf,"%s",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto job_fail;
	}

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_UFIP_E,strlen(SM_XSD_UFIP_E));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CD_CMD_E,strlen(SM_XSD_CD_CMD_E));
	if(rc) return -1;

	if(tmp_buf != NULL){
		free(tmp_buf);
	}

	return 0;

job_fail:
	if(tmp_buf != NULL){
		free(tmp_buf);
	}	
}



int sm_create_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"create");
		if(rc) return -1;
		return 0;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
		
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CREATE_CMD_S,strlen(SM_XSD_CREATE_CMD_S));
	if(rc) return -1;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) return -1;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CREATE_CMD_E,strlen(SM_XSD_CREATE_CMD_E));
	if(rc) return -1;
	
	return 0;		
}


int sm_exit_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"exit");
		if(rc) return -1;
		return 0;
	}
	return 0;
}



int sm_load_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"load");
		if(rc) return -1;
		return 0;
	}
	return 0;
}

int sm_set_cmd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;

	if( rsp_msg_buf->option & SMASH_OPT_HELP){
		rc = cmd_help_xml_msg(msg_in,rsp_msg_buf,"set");
		if(rc) return -1;
		return 0;
	}
	return 0;
}


int do_show_level_job(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	int rc = -1;
	int joberr = 1;
	int status = 1;
	char *tmp_buf = NULL;

	switch(rsp_msg_buf->level_state){
		case 0x0:
		{
			rc = append_rsp_msg(rsp_msg_buf,XSD_HEADER_STR,strlen(XSD_HEADER_STR));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_S,strlen(SM_XSD_CMD_S));
			if(rc) goto do_show_level_job_fail;
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_job_fail;
				
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_S,strlen(SM_XSD_INPUTLINE_S));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,msg_in,strlen(msg_in));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_E,strlen(SM_XSD_INPUTLINE_E));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_E,strlen(SM_XSD_CMD_E));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_job_fail;
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_S,strlen(SM_XSD_CMDSTAT_S));
			if(rc) goto do_show_level_job_fail;
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_S,strlen(SM_XSD_STATUS_S));
			if(rc) goto do_show_level_job_fail;
		
			if(rsp_msg_buf->status == CMD_ST_NO_SETTING)
			{
				printf("1:Don't have correct status!\n");
				goto do_show_level_job_fail;
			}
		
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf == NULL) goto do_show_level_job_fail;
			sprintf(tmp_buf,"%d",rsp_msg_buf->status);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			free(tmp_buf);
			tmp_buf = NULL;
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_E,strlen(SM_XSD_STATUS_E));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_S,strlen(SM_XSD_STATUSTAG_S));
			if(rc) goto do_show_level_job_fail;	
			
			rc = append_rsp_msg(rsp_msg_buf,sm_cmd_status_tag_tbl[rsp_msg_buf->status].status_tag,sm_cmd_status_tag_tbl[rsp_msg_buf->status].str_len);
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_E,strlen(SM_XSD_STATUSTAG_E));
			if(rc) goto do_show_level_job_fail;
				
		
			if(rsp_msg_buf->error != 0){
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
				if(rc) return -1;
					
				tmp_buf = (char*)calloc(1024,1);
				if(tmp_buf == NULL) return -1;
				sprintf(tmp_buf,"<error>%d</error>\n",rsp_msg_buf->error);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				free(tmp_buf);
				tmp_buf = NULL;
				if(rc) goto do_show_level_job_fail;		
		
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
				if(rc) goto do_show_level_job_fail;
				
				for(i=0;i<sizeof(sm_err_tbl)/sizeof(SM_ERROR_TBL);i++){
					if(rsp_msg_buf->error == sm_err_tbl[i].error)
						break;
				}
		
				tmp_buf = (char*)calloc(1024,1);
				if(tmp_buf == NULL) goto do_show_level_job_fail;
				sprintf(tmp_buf,"<error_tag>%s</error_tag>\n",sm_err_tbl[i].err_tag);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_job_fail;
				free(tmp_buf);
				tmp_buf = NULL;
				
		
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
				if(rc) goto do_show_level_job_fail;
		
				if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
					rc = append_rsp_msg(rsp_msg_buf,"<cd></cd>\n",strlen("<cd></cd>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
					rc = append_rsp_msg(rsp_msg_buf,"<delete></delete>\n",strlen("<delete></delete>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
					rc = append_rsp_msg(rsp_msg_buf,"<dump></dump>\n",strlen("<dump></dump>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
					rc = append_rsp_msg(rsp_msg_buf,"<exit></exit>\n",strlen("<exit></exit>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
					rc = append_rsp_msg(rsp_msg_buf,"<help></help>\n",strlen("<help></help>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
					rc = append_rsp_msg(rsp_msg_buf,"<load></load>\n",strlen("<load></load>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
					rc = append_rsp_msg(rsp_msg_buf,"<reset></reset>\n",strlen("<reset></reset>\n"));
					if(rc) goto do_show_level_job_fail;		
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
					rc = append_rsp_msg(rsp_msg_buf,"<set></set>\n",strlen("<set></set>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
					rc = append_rsp_msg(rsp_msg_buf,"<show></show>\n",strlen("<show></show>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
					rc = append_rsp_msg(rsp_msg_buf,"<start></start>\n",strlen("<start></start>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
					rc = append_rsp_msg(rsp_msg_buf,"<stop></stop>\n",strlen("<stop></stop>\n"));
					if(rc) goto do_show_level_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
					rc = append_rsp_msg(rsp_msg_buf,"<version></version>\n",strlen("<version></version>\n"));
					if(rc) goto do_show_level_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
					rc = append_rsp_msg(rsp_msg_buf,"<create></create>\n",strlen("<create></create>\n"));
					if(rc) goto do_show_level_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
					rc = append_rsp_msg(rsp_msg_buf,"<oemverb></oemverb>\n",strlen("<oemverb></oemverb>\n"));
					if(rc) goto do_show_level_job_fail;
				}else{
					printf("Verb Cannot Found!\n");
					return -1;
				}
				
				rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
				if(rc) goto do_show_level_job_fail;
				
				return 0;
			}
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_S,strlen(SM_XSD_JOB_S));
			if(rc) goto do_show_level_job_fail;
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_S,strlen(SM_XSD_JOBID_S));
			if(rc) goto do_show_level_job_fail;
			
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf == NULL) goto do_show_level_job_fail;
			sprintf(tmp_buf,"%d",rsp_msg_buf->job_id);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_job_fail;	
			if(tmp_buf){
				free(tmp_buf);
				tmp_buf = NULL;
			}
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_E,strlen(SM_XSD_JOBID_E));
			if(rc) goto do_show_level_job_fail;
		
			if(rsp_msg_buf->status){
				rc = sm_cmd_fail(msg_in,rsp_msg_buf);
				if(rc) goto do_show_level_job_fail;
			}
			
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_E,strlen(SM_XSD_JOB_E));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_E,strlen(SM_XSD_CMDSTAT_E));
			if(rc) goto do_show_level_job_fail;
				

				
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;
	
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_S,strlen(SM_XSD_SHOW_CMD_S));
			if(rc) return -1;
				
			if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
				rc = sm_show_level_cmd_msg(msg_in,rsp_msg_buf);
				if(rc) return -1;
			}
		}			
			break;
		case 0x1:
			if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
				rc = sm_show_level_cmd_msg(msg_in,rsp_msg_buf);
				if(rc) return -1;
			}
			break;
		case 0x2:		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_E,strlen(SM_XSD_SHOW_CMD_E));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
			if(rc) return -1;
				
			break;
		default:
			printf("Error: Level State Not Support!\n");
			return -1;
	}
	
	if(tmp_buf)	free(tmp_buf);
	return 0;

do_show_level_job_fail:
	if(tmp_buf)	free(tmp_buf);	
	return -1;	
}


int do_parse_job(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	int rc = -1;
	int joberr = 1;
	int status = 1;
	char *tmp_buf = NULL;


	
	rc = append_rsp_msg(rsp_msg_buf,XSD_HEADER_STR,strlen(XSD_HEADER_STR));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_S,strlen(SM_XSD_CMD_S));
	if(rc) goto parse_cd_fail;


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) goto parse_cd_fail;
		

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_S,strlen(SM_XSD_INPUTLINE_S));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,msg_in,strlen(msg_in));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_E,strlen(SM_XSD_INPUTLINE_E));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_E,strlen(SM_XSD_CMD_E));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) goto parse_cd_fail;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_S,strlen(SM_XSD_CMDSTAT_S));
	if(rc) goto parse_cd_fail;
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_S,strlen(SM_XSD_STATUS_S));
	if(rc) goto parse_cd_fail;

	if(rsp_msg_buf->status == CMD_ST_NO_SETTING)
	{
		printf("1:Don't have correct status!\n");
		goto parse_cd_fail;
	}

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) goto parse_cd_fail;
	sprintf(tmp_buf,"%d",rsp_msg_buf->status);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	free(tmp_buf);
	tmp_buf = NULL;
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_E,strlen(SM_XSD_STATUS_E));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_S,strlen(SM_XSD_STATUSTAG_S));
	if(rc) goto parse_cd_fail;	
	
	rc = append_rsp_msg(rsp_msg_buf,sm_cmd_status_tag_tbl[rsp_msg_buf->status].status_tag,sm_cmd_status_tag_tbl[rsp_msg_buf->status].str_len);
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_E,strlen(SM_XSD_STATUSTAG_E));
	if(rc) goto parse_cd_fail;
		

	if(rsp_msg_buf->error != 0){
		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) return -1;
			
		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) return -1;
		sprintf(tmp_buf,"<error>%d</error>\n",rsp_msg_buf->error);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		free(tmp_buf);
		tmp_buf = NULL;
		if(rc) goto parse_cd_fail;		

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
		if(rc) goto parse_cd_fail;
		
		for(i=0;i<sizeof(sm_err_tbl)/sizeof(SM_ERROR_TBL);i++){
			if(rsp_msg_buf->error == sm_err_tbl[i].error)
				break;
		}

		tmp_buf = (char*)calloc(1024,1);
		if(tmp_buf == NULL) goto parse_cd_fail;
		sprintf(tmp_buf,"<error_tag>%s</error_tag>\n",sm_err_tbl[i].err_tag);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto parse_cd_fail;
		free(tmp_buf);
		tmp_buf = NULL;
		

		rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
		if(rc) goto parse_cd_fail;

		if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
			rc = append_rsp_msg(rsp_msg_buf,"<cd></cd>\n",strlen("<cd></cd>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
			rc = append_rsp_msg(rsp_msg_buf,"<delete></delete>\n",strlen("<delete></delete>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
			rc = append_rsp_msg(rsp_msg_buf,"<dump></dump>\n",strlen("<dump></dump>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
			rc = append_rsp_msg(rsp_msg_buf,"<exit></exit>\n",strlen("<exit></exit>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
			rc = append_rsp_msg(rsp_msg_buf,"<help></help>\n",strlen("<help></help>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
			rc = append_rsp_msg(rsp_msg_buf,"<load></load>\n",strlen("<load></load>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
			rc = append_rsp_msg(rsp_msg_buf,"<reset></reset>\n",strlen("<reset></reset>\n"));
			if(rc) goto parse_cd_fail;		
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
			rc = append_rsp_msg(rsp_msg_buf,"<set></set>\n",strlen("<set></set>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
			rc = append_rsp_msg(rsp_msg_buf,"<show></show>\n",strlen("<show></show>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
			rc = append_rsp_msg(rsp_msg_buf,"<start></start>\n",strlen("<start></start>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
			rc = append_rsp_msg(rsp_msg_buf,"<stop></stop>\n",strlen("<stop></stop>\n"));
			if(rc) goto parse_cd_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
			rc = append_rsp_msg(rsp_msg_buf,"<version></version>\n",strlen("<version></version>\n"));
			if(rc) goto parse_cd_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
			rc = append_rsp_msg(rsp_msg_buf,"<create></create>\n",strlen("<create></create>\n"));
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
			rc = append_rsp_msg(rsp_msg_buf,"<oemverb></oemverb>\n",strlen("<oemverb></oemverb>\n"));
			if(rc) goto parse_cd_fail;
		}else{
			printf("Verb Cannot Found!\n");
			return -1;
		}
		
		rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
		if(rc) goto parse_cd_fail;
		goto free_source;
	}


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_S,strlen(SM_XSD_JOB_S));
	if(rc) goto parse_cd_fail;


	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_S,strlen(SM_XSD_JOBID_S));
	if(rc) goto parse_cd_fail;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) goto parse_cd_fail;
	sprintf(tmp_buf,"%d",rsp_msg_buf->job_id);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto parse_cd_fail;	
	if(tmp_buf){
		free(tmp_buf);
		tmp_buf = NULL;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_E,strlen(SM_XSD_JOBID_E));
	if(rc) goto parse_cd_fail;

	if(rsp_msg_buf->status){
		rc = sm_cmd_fail(msg_in,rsp_msg_buf);
		if(rc) goto parse_cd_fail;
	}

	
	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_E,strlen(SM_XSD_JOB_E));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
	if(rc) goto parse_cd_fail;

	rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_E,strlen(SM_XSD_CMDSTAT_E));
	if(rc) goto parse_cd_fail;

{
		if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
			rc = sm_cd_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){
			rc = sm_delete_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
			rc = sm_dump_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){			
			rc = sm_exit_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
			rc = sm_help_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
			rc = sm_load_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
			rc = sm_reset_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
			rc = sm_set_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
			rc = sm_show_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
			rc = sm_start_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
			rc = sm_stop_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
			rc = sm_version_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
			rc = sm_create_cmd_msg(msg_in,rsp_msg_buf);
			if(rc) goto parse_cd_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
			printf("Verb oemverb Not Support\n");
			goto parse_cd_fail;
		}else{
			printf("Verb Cannot Found!\n");
			goto parse_cd_fail;
		}
}

	rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
	if(rc) goto parse_cd_fail;
free_source:
	if(tmp_buf) free(tmp_buf);
	return 0;
			
parse_cd_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;
}



int realloc_mem(RSP_MSG_BUF_TAG *rsp_msg_buf)
{
#ifdef SM_XSD_DBG
printf("BF_ReloMem API: data addr is %d\n",(unsigned int)rsp_msg_buf->data);
#endif

	if(rsp_msg_buf->total_sz*2 > SM_MEM_MAX_SZ){
		if(rsp_msg_buf->data != NULL) free(rsp_msg_buf->data);
		printf("Reallocate Mem Failed\n");
		return -1;
	}
	
	rsp_msg_buf->data = (char*)calloc(rsp_msg_buf->total_sz*2,1);
	if(rsp_msg_buf->data == NULL){
		printf("Reallocate Mem Failed\n");
		return -1;
	}
	rsp_msg_buf->total_sz = rsp_msg_buf->total_sz*2;

#ifdef SM_XSD_DBG
printf("AF_ReloMem API: data addr is %d\n",(unsigned int)rsp_msg_buf->data);
#endif

	return 0;
}


int append_rsp_msg(RSP_MSG_BUF_TAG *rsp_msg_buf,char *add_data,int size)
{
	int rc=-1;
	char *old_msg_buf;
	unsigned int old_msg_sz,old_total_sz;

#ifdef SM_XSD_DBG
printf("BF_Append API: data addr is %d\n",(unsigned int)rsp_msg_buf->data);
#endif
	
	old_msg_buf = rsp_msg_buf->data;
	old_msg_sz = rsp_msg_buf->msg_sz;
	old_total_sz = rsp_msg_buf->total_sz;
	
	while((rsp_msg_buf->msg_sz + size) > rsp_msg_buf->total_sz)
	{
		if(old_total_sz != rsp_msg_buf->total_sz){
			if(rsp_msg_buf->data != NULL) free(rsp_msg_buf->data);
			rc = realloc_mem(rsp_msg_buf);
			if(rc){
				printf("Reallocate Mem Failed\n");
				return -1;
			}
			continue;
		}
		
		rc = realloc_mem(rsp_msg_buf);
		if(rc){
			printf("Reallocate Mem Failed\n");
			return -1;
		}
	}
		
	
	if(old_total_sz != rsp_msg_buf->total_sz){
		memcpy(rsp_msg_buf->data,old_msg_buf,old_msg_sz);
		memcpy(rsp_msg_buf->data+old_msg_sz,add_data,size);
		rsp_msg_buf->msg_sz = old_msg_sz + size;
		free(old_msg_buf);
	}else{
		memcpy(rsp_msg_buf->data+old_msg_sz,add_data,size);
		rsp_msg_buf->msg_sz += size;
	}

#ifdef SM_XSD_DBG
printf("AF_Append API: data addr is %d\n",(unsigned int)rsp_msg_buf->data);
#endif
	
	return 0;
}













int sm_cd_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_cd_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will cd %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_cd_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}
		
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_cd_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_cd_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_cd_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_cd_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_create_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_create_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will create %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_create_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}
	
	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=instance\n",strlen("begingroup=instance\n"));
		if(rc) goto sm_create_cmd_kd_msg_fail;		
	}


	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_create_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_create_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_create_cmd_kd_msg_fail;
	}

	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
		if(rc) goto sm_create_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_create_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_delete_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_delete_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will delete %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_delete_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}
	
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_delete_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_delete_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_delete_cmd_kd_msg_fail;
	}

free_source:
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_delete_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_dump_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
		
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_dump_cmd_kd_msg_fail;

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will dump %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_dump_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}
	
	rc = append_rsp_msg(rsp_msg_buf,"begingroup=source\n",strlen("begingroup=source\n"));
	if(rc) goto sm_dump_cmd_kd_msg_fail;

	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_dump_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_dump_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_dump_cmd_kd_msg_fail;
	}


	rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
	if(rc) goto sm_dump_cmd_kd_msg_fail;
	
	rc = append_rsp_msg(rsp_msg_buf,"begingroup=destination\n",strlen("begingroup=source\n"));
	if(rc) goto sm_dump_cmd_kd_msg_fail;

	rc = append_rsp_msg(rsp_msg_buf,"uri=ftp://admin:pwd@aten.com/index.html\n",strlen("uri=ftp://admin:pwd@aten.com/index.html\n"));
	if(rc) goto sm_dump_cmd_kd_msg_fail;

	rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
	if(rc) goto sm_dump_cmd_kd_msg_fail;

free_source:
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_dump_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_help_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_help_cmd_kd_msg_fail;
	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will return help about %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_help_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_help_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_load_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
		
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_load_cmd_kd_msg_fail;
	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will load %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_load_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}

	
	rc = append_rsp_msg(rsp_msg_buf,"begingroup=source\n",strlen("begingroup=source\n"));
	if(rc) goto sm_load_cmd_kd_msg_fail;


	rc = append_rsp_msg(rsp_msg_buf,"ftp://admin:pwd@aten.com/firmware.img\n",strlen("ftp://admin:pwd@aten.com/firmware.img\n"));
	if(rc) goto sm_load_cmd_kd_msg_fail;

	rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
	if(rc) goto sm_load_cmd_kd_msg_fail;
	
	rc = append_rsp_msg(rsp_msg_buf,"begingroup=destination\n",strlen("begingroup=source\n"));
	if(rc) goto sm_load_cmd_kd_msg_fail;

	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_load_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_load_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_load_cmd_kd_msg_fail;
	}

	rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
	if(rc) goto sm_load_cmd_kd_msg_fail;

free_source:
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_load_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_reset_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_reset_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will reset %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_reset_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}

		
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_reset_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_reset_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_reset_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_reset_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_reset_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_set_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_set_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will set %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_set_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}



	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=instance\n",strlen("begingroup=instance\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;		
	}

		
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}

	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=property\n",strlen("begingroup=property\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;
					
		rc = append_rsp_msg(rsp_msg_buf,"property_name=enabledcapabilities\n",strlen("property_name=enabledcapabilities\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;
		
		rc = append_rsp_msg(rsp_msg_buf,"property_val=3\n",strlen("property_val=3\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;

		rc = append_rsp_msg(rsp_msg_buf,"property_valstring=wakeonlan\n",strlen("property_valstring=wakeonlan\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;

		rc = append_rsp_msg(rsp_msg_buf,"property_val=2\n",strlen("property_val=2\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;

		rc = append_rsp_msg(rsp_msg_buf,"property_valstring=alertonlan\n",strlen("property_valstring=alertonlan\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}	
	

	if(0){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}
	
	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
		if(rc) goto sm_set_cmd_kd_msg_fail;
	}	
	
free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_set_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}


int sm_show_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *ch_pos=NULL;
	FILE *fp=NULL;
	char *file_name=NULL;
	char *tmp_buf=NULL;
	char *tmp_buf2=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_show_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will show %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_show_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}


	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=instance\n",strlen("begingroup=instance\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;		
	}


	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->ppid != 0){

		tmp_buf2 =  calloc(1024,1);
		if(tmp_buf2 == NULL)
			goto sm_show_cmd_kd_msg_fail;
		file_name = calloc(1024,1);
		if(file_name == NULL)
			goto sm_show_cmd_kd_msg_fail;

		sprintf(file_name,"/tmp/smash_%d",rsp_msg_buf->ppid);
		fp = fopen(file_name,"r");

		if(fp != NULL){
			while(fgets(tmp_buf,1024,fp)){
				ch_pos=strchr(tmp_buf,'=');
				if(ch_pos == 0){
					break;
				}
				
				rc = append_rsp_msg(rsp_msg_buf,"begingroup=property\n",strlen("begingroup=property\n"));
				if(rc) goto sm_show_cmd_kd_msg_fail;

				*ch_pos = 0;

				sprintf(tmp_buf2,"property_name=%s\n",tmp_buf);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf2,strlen(tmp_buf2));
				if(rc) goto sm_show_cmd_kd_msg_fail;
				ch_pos++;
				sprintf(tmp_buf2,"property_val=%s",ch_pos);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf2,strlen(tmp_buf2));
				if(rc) goto sm_show_cmd_kd_msg_fail;

				rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
				if(rc) goto sm_show_cmd_kd_msg_fail;				
			}

			fclose(fp);
			fp = NULL;
		}
	}

	
	if(strlen(rsp_msg_buf->targets)!=0){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=targets\n",strlen("begingroup=targets\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;
			
		rc = append_rsp_msg(rsp_msg_buf,rsp_msg_buf->targets,strlen(rsp_msg_buf->targets));
		if(rc) goto sm_show_cmd_kd_msg_fail;		

		rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->support_verbs != -1){
		rc = append_rsp_msg(rsp_msg_buf,"begingroup=verbs\n",strlen("begingroup=verbs\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;
		memset(tmp_buf,0,1024);
		if(rsp_msg_buf->support_verbs & CD_CMD)
			strcat(tmp_buf,"verb=cd\n");
		if(rsp_msg_buf->support_verbs & SHOW_CMD)
			strcat(tmp_buf,"verb=show\n");
		if(rsp_msg_buf->support_verbs & HELP_CMD)
			strcat(tmp_buf,"verb=help\n");
		if(rsp_msg_buf->support_verbs & VERSION_CMD)
			strcat(tmp_buf,"verb=version\n");
		if(rsp_msg_buf->support_verbs & EXIT_CMD)
			strcat(tmp_buf,"verb=exit\n");
		if(rsp_msg_buf->support_verbs & DELETE_CMD)
			strcat(tmp_buf,"verb=delete\n");
		if(rsp_msg_buf->support_verbs & START_CMD)
			strcat(tmp_buf,"verb=start\n");
		if(rsp_msg_buf->support_verbs & STOP_CMD)
			strcat(tmp_buf,"verb=stop\n");
		if(rsp_msg_buf->support_verbs & RESET_CMD)
			strcat(tmp_buf,"verb=reset\n");
		if(rsp_msg_buf->support_verbs & DUMP_CMD)
			strcat(tmp_buf,"verb=dump\n");
		if(rsp_msg_buf->support_verbs & SET_CMD)
			strcat(tmp_buf,"verb=set\n");
		if(rsp_msg_buf->support_verbs & LOAD_CMD)
			strcat(tmp_buf,"verb=load\n");
		if(rsp_msg_buf->support_verbs & CREATE_CMD)
			strcat(tmp_buf,"verb=create\n");
	
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	
		rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}
	

	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}
	
	if(1){
		rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
		if(rc) goto sm_show_cmd_kd_msg_fail;
	}	
	

free_source:	
	if(tmp_buf)   free(tmp_buf);
	if(tmp_buf2)  free(tmp_buf2);
	if(file_name) free(file_name);
	if(fp)		fclose(fp);
	return 0;
	
sm_show_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	if(tmp_buf2) free(tmp_buf2);
	if(file_name) free(file_name);
	if(fp)		fclose(fp);
	return -1;	
}

int sm_start_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_start_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will start %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_start_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}
		
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_start_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_start_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_start_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_start_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_start_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}

int sm_stop_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_stop_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"examine=If run without the examine option, this command will stop %s.\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto sm_stop_cmd_kd_msg_fail;
				goto free_source;
			}
			goto free_source;
		}
	}else{
		goto free_source;
	}

		
	if(rsp_msg_buf->ufct != NULL){
		sprintf(tmp_buf,"ufct=%s\n",rsp_msg_buf->ufct);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_stop_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->inst_num != NULL){
		sprintf(tmp_buf,"instance=%s\n",rsp_msg_buf->inst_num);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_stop_cmd_kd_msg_fail;
	}

	if(rsp_msg_buf->ufip != NULL){
		sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_stop_cmd_kd_msg_fail;
	}


	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_stop_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_stop_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}


int sm_version_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_version_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			sprintf(tmp_buf,"examine=If run without the examine option, this command will show smash clp version.\n");
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto sm_version_cmd_kd_msg_fail;			
			goto free_source;
		}
	}else{
		goto free_source;
	}
		
	rc = append_rsp_msg(rsp_msg_buf,"clpversion=v1.0.0\n",strlen("clpversion=v1.0.0\n"));
	if(rc) goto sm_version_cmd_kd_msg_fail;
	
	rc = append_rsp_msg(rsp_msg_buf,"addressingversion=v1.0.0\n",strlen("addressingversion=v1.0.0\n"));
	if(rc) goto sm_version_cmd_kd_msg_fail;


	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_version_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_version_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}


int sm_exit_cmd_kd_msg(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	char date[26] = {0};
	char *tmp_buf=NULL;
	int rc = -1;
	
	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) return -1;
	
	sprintf(tmp_buf,"command=%s\n",rsp_msg_buf->cmd);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto sm_exit_cmd_kd_msg_fail;	

	if( rsp_msg_buf->status == CMD_ST_COMPLETED ){
		if( rsp_msg_buf->option & SMASH_OPT_EXAMINE ){
			sprintf(tmp_buf,"examine=If run without the examine option, this command will exit smash clp.\n");
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto sm_exit_cmd_kd_msg_fail;			
			goto free_source;
		}
	}else{
		goto free_source;
	}

	if(rsp_msg_buf->option & SMASH_OPT_WAIT){
		getDateTime(date);
		sprintf(tmp_buf,"timestamp=%s\n",date);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto sm_exit_cmd_kd_msg_fail;
	}

free_source:	
	if(tmp_buf) free(tmp_buf);
	return 0;
	
sm_exit_cmd_kd_msg_fail:
	if(tmp_buf) free(tmp_buf);
	return -1;	
}


#if 0
int do_show_level_keyword_job(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	int rc = -1;
	int joberr = 1;
	int status = 1;
	char *tmp_buf = NULL;

	switch(rsp_msg_buf->level_state){
		case 0x0:
		{
			rc = append_rsp_msg(rsp_msg_buf,XSD_HEADER_STR,strlen(XSD_HEADER_STR));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_S,strlen(SM_XSD_CMD_S));
			if(rc) goto do_show_level_keyword_job_fail;
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_keyword_job_fail;
				
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_S,strlen(SM_XSD_INPUTLINE_S));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,msg_in,strlen(msg_in));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_INPUTLINE_E,strlen(SM_XSD_INPUTLINE_E));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMD_E,strlen(SM_XSD_CMD_E));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_keyword_job_fail;
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_S,strlen(SM_XSD_CMDSTAT_S));
			if(rc) goto do_show_level_keyword_job_fail;
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_S,strlen(SM_XSD_STATUS_S));
			if(rc) goto do_show_level_keyword_job_fail;
		
			if(rsp_msg_buf->status == CMD_ST_NO_SETTING)
			{
				printf("1:Don't have correct status!\n");
				goto do_show_level_keyword_job_fail;
			}
		
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf == NULL) goto do_show_level_keyword_job_fail;
			sprintf(tmp_buf,"%d",rsp_msg_buf->status);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			free(tmp_buf);
			tmp_buf = NULL;
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUS_E,strlen(SM_XSD_STATUS_E));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_S,strlen(SM_XSD_STATUSTAG_S));
			if(rc) goto do_show_level_keyword_job_fail;	
			
			rc = append_rsp_msg(rsp_msg_buf,sm_cmd_status_tag_tbl[rsp_msg_buf->status].status_tag,sm_cmd_status_tag_tbl[rsp_msg_buf->status].str_len);
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_STATUSTAG_E,strlen(SM_XSD_STATUSTAG_E));
			if(rc) goto do_show_level_keyword_job_fail;
				
		
			if(rsp_msg_buf->error != 0){
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
				if(rc) return -1;
					
				tmp_buf = (char*)calloc(1024,1);
				if(tmp_buf == NULL) return -1;
				sprintf(tmp_buf,"<error>%d</error>\n",rsp_msg_buf->error);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				free(tmp_buf);
				tmp_buf = NULL;
				if(rc) goto do_show_level_keyword_job_fail;		
		
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
				if(rc) goto do_show_level_keyword_job_fail;
				
				for(i=0;i<sizeof(sm_err_tbl)/sizeof(SM_ERROR_TBL);i++){
					if(rsp_msg_buf->error == sm_err_tbl[i].error)
						break;
				}
		
				tmp_buf = (char*)calloc(1024,1);
				if(tmp_buf == NULL) goto do_show_level_keyword_job_fail;
				sprintf(tmp_buf,"<error_tag>%s</error_tag>\n",sm_err_tbl[i].err_tag);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_keyword_job_fail;
				free(tmp_buf);
				tmp_buf = NULL;
				
		
				rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
				if(rc) goto do_show_level_keyword_job_fail;
		
				if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
					rc = append_rsp_msg(rsp_msg_buf,"<cd></cd>\n",strlen("<cd></cd>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
					rc = append_rsp_msg(rsp_msg_buf,"<delete></delete>\n",strlen("<delete></delete>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
					rc = append_rsp_msg(rsp_msg_buf,"<dump></dump>\n",strlen("<dump></dump>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
					rc = append_rsp_msg(rsp_msg_buf,"<exit></exit>\n",strlen("<exit></exit>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
					rc = append_rsp_msg(rsp_msg_buf,"<help></help>\n",strlen("<help></help>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
					rc = append_rsp_msg(rsp_msg_buf,"<load></load>\n",strlen("<load></load>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
					rc = append_rsp_msg(rsp_msg_buf,"<reset></reset>\n",strlen("<reset></reset>\n"));
					if(rc) goto do_show_level_keyword_job_fail;		
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
					rc = append_rsp_msg(rsp_msg_buf,"<set></set>\n",strlen("<set></set>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
					rc = append_rsp_msg(rsp_msg_buf,"<show></show>\n",strlen("<show></show>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
					rc = append_rsp_msg(rsp_msg_buf,"<start></start>\n",strlen("<start></start>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
					rc = append_rsp_msg(rsp_msg_buf,"<stop></stop>\n",strlen("<stop></stop>\n"));
					if(rc) goto do_show_level_keyword_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
					rc = append_rsp_msg(rsp_msg_buf,"<version></version>\n",strlen("<version></version>\n"));
					if(rc) goto do_show_level_keyword_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
					rc = append_rsp_msg(rsp_msg_buf,"<create></create>\n",strlen("<create></create>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
					rc = append_rsp_msg(rsp_msg_buf,"<oemverb></oemverb>\n",strlen("<oemverb></oemverb>\n"));
					if(rc) goto do_show_level_keyword_job_fail;
				}else{
					printf("Verb Cannot Found!\n");
					goto do_show_level_keyword_job_fail;
				}
				
				rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
				if(rc) goto do_show_level_keyword_job_fail;
				
				return 0;
			}
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_S,strlen(SM_XSD_JOB_S));
			if(rc) goto do_show_level_keyword_job_fail;
		
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_3TAB,strlen(SM_XSD_3TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_S,strlen(SM_XSD_JOBID_S));
			if(rc) goto do_show_level_keyword_job_fail;
			
			tmp_buf = (char*)calloc(1024,1);
			if(tmp_buf == NULL) goto do_show_level_keyword_job_fail;
			sprintf(tmp_buf,"%d",rsp_msg_buf->job_id);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_keyword_job_fail;	
			if(tmp_buf){
				free(tmp_buf);
				tmp_buf = NULL;
			}
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOBID_E,strlen(SM_XSD_JOBID_E));
			if(rc) goto do_show_level_keyword_job_fail;
		
			if(rsp_msg_buf->status){
				rc = sm_cmd_fail(msg_in,rsp_msg_buf);
				if(rc) goto do_show_level_keyword_job_fail;
			}
			
			
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_2TAB,strlen(SM_XSD_2TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_JOB_E,strlen(SM_XSD_JOB_E));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) goto do_show_level_keyword_job_fail;
		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_CMDSTAT_E,strlen(SM_XSD_CMDSTAT_E));
			if(rc) goto do_show_level_keyword_job_fail;
				

				
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;
	
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_S,strlen(SM_XSD_SHOW_CMD_S));
			if(rc) return -1;
				
			if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
				rc = sm_show_level_cmd_msg(msg_in,rsp_msg_buf);
				if(rc) return -1;
			}
		}			
			break;
		case 0x1:
			if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
				rc = sm_show_level_cmd_msg(msg_in,rsp_msg_buf);
				if(rc) return -1;
			}
			break;
		case 0x2:		
			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_1TAB,strlen(SM_XSD_1TAB));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,SM_XSD_SHOW_CMD_E,strlen(SM_XSD_SHOW_CMD_E));
			if(rc) return -1;

			rc = append_rsp_msg(rsp_msg_buf,XSD_RESPONSE_TAIL,strlen(XSD_RESPONSE_TAIL));
			if(rc) return -1;
				
			break;
		default:
			printf("Error: Level State Not Support!\n");
			return -1;
	}
	
	if(tmp_buf)	free(tmp_buf);
	return 0;

do_show_level_keyword_job_fail:
	if(tmp_buf)	free(tmp_buf);	
	return -1;	
}
#endif


int do_show_level_kd_job(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	int rc = -1;
	int joberr = 1;
	int status = 1;
	char *tmp_buf = NULL;
	char *tmp_buf2 = NULL;
	char *file_name = NULL;
	FILE *fp=NULL;
	char *ch_pos=NULL;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) goto do_show_level_kd_job_fail;



	switch(rsp_msg_buf->level_state){
		case 0x0:
		{

			sprintf(tmp_buf,"commandline=%s\n",msg_in);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_kd_job_fail;
		
			sprintf(tmp_buf,"status=%d\n",rsp_msg_buf->status);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_kd_job_fail;
		
			sprintf(tmp_buf,"status_tag=%s\n",sm_cmd_status_tag_tbl[rsp_msg_buf->status].status_tag);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_kd_job_fail;
		
			if(rsp_msg_buf->error != 0){
				sprintf(tmp_buf,"error=%d\n",rsp_msg_buf->error);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
		
		
				for(i=0;i<sizeof(sm_err_tbl)/sizeof(SM_ERROR_TBL);i++){
					if(rsp_msg_buf->error == sm_err_tbl[i].error)
						break;
				}
		
				sprintf(tmp_buf,"error_tag=%s\n",sm_err_tbl[i].err_tag);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
			}

			sprintf(tmp_buf,"job_id=%d\n",rsp_msg_buf->job_id);
			rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
			if(rc) goto do_show_level_kd_job_fail;
    		
			if(rsp_msg_buf->errtype != -1){
				sprintf(tmp_buf,"errtype=%d\n",rsp_msg_buf->errtype);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
    		
				sprintf(tmp_buf,"errtype_desc=%s\n",sm_err_type_tbl[rsp_msg_buf->errtype].err_desc);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;		
			}

			if(rsp_msg_buf->cimstat != -1){
    		
				sprintf(tmp_buf,"cimstat=%d\n",rsp_msg_buf->cimstat);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
    		
				for(i=0;i<sizeof(sm_cim_status_tbl)/sizeof(SM_CIM_STATUS_TBL);i++){
					if(sm_cim_status_tbl[i].cimstat == rsp_msg_buf->cimstat){
						break;
					}
				}
			
				sprintf(tmp_buf,"cimstat_desc=%s\n",sm_cim_status_tbl[i].cimstat_desc);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
			}

			if(rsp_msg_buf->severity != EL_SERVERITY_NO_SETTING){
				sprintf(tmp_buf,"severity=%d\n",rsp_msg_buf->severity);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
    		
				for(i=0;i<sizeof(sm_severity_tbl)/sizeof(SM_SEVERITY_TBL);i++){
					if(sm_severity_tbl[i].sev_num == rsp_msg_buf->severity)
						break;
				}
    		
				sprintf(tmp_buf,"severity_desc=%s\n",sm_severity_tbl[i].sev_desc);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
			}

			if(rsp_msg_buf->error != 0){
				if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
					rc = append_rsp_msg(rsp_msg_buf,"command=cd\n",strlen("command=cd\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
					rc = append_rsp_msg(rsp_msg_buf,"command=delete\n",strlen("command=delete\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
					
					if(rsp_msg_buf->probcause_num != -1){
						sprintf(tmp_buf,"probcause=%d\n",rsp_msg_buf->probcause_num);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
						if(rc) goto do_show_level_kd_job_fail;
						
						sprintf(tmp_buf,"probcause_desc=%s\n",sm_probcause_tbl[rsp_msg_buf->probcause_num].probcause_desc);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
						if(rc) goto do_show_level_kd_job_fail;
					}
				
					rc = append_rsp_msg(rsp_msg_buf,"command=dump\n",strlen("command=dump\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
					rc = append_rsp_msg(rsp_msg_buf,"command=exit\n",strlen("command=exit\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
					rc = append_rsp_msg(rsp_msg_buf,"command=help\n",strlen("command=help\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
					rc = append_rsp_msg(rsp_msg_buf,"command=load\n",strlen("command=load\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
					rc = append_rsp_msg(rsp_msg_buf,"command=reset\n",strlen("command=reset\n"));
					if(rc) goto do_show_level_kd_job_fail;		
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
					
    		
 					if(rsp_msg_buf->probcause_num != -1){
						sprintf(tmp_buf,"probcause=%d\n",rsp_msg_buf->probcause_num);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
						if(rc) goto do_show_level_kd_job_fail;
						
						sprintf(tmp_buf,"probcause_desc=%s\n",sm_probcause_tbl[rsp_msg_buf->probcause_num].probcause_desc);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
						if(rc) goto do_show_level_kd_job_fail;
					}
			
					if(rsp_msg_buf->recmdaction != NULL){
						sprintf(tmp_buf,"recmdaction=%s\n",rsp_msg_buf->recmdaction);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
						if(rc) goto do_show_level_kd_job_fail;
					}
					
					if(rsp_msg_buf->message_id != -1){
						rc = append_rsp_msg(rsp_msg_buf,"begingroup=message\n",strlen("begingroup=message\n"));
						if(rc) goto do_show_level_kd_job_fail;
    		
						if(rsp_msg_buf->owningentity != NULL){
							sprintf(tmp_buf,"owningentity=%s\n",rsp_msg_buf->owningentity);
							rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
							if(rc) goto do_show_level_kd_job_fail;
						}
    		
						if(rsp_msg_buf->message_id != -1){
							sprintf(tmp_buf,"message_id=%d\n",rsp_msg_buf->message_id);
							rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
							if(rc) goto do_show_level_kd_job_fail;
						}
    		
    		
						if(rsp_msg_buf->message != NULL){
							sprintf(tmp_buf,"message=%s\n",rsp_msg_buf->message);
							rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
							if(rc) goto do_show_level_kd_job_fail;
						}
						
						if(rsp_msg_buf->message_arg != -1){
							sprintf(tmp_buf,"message_arg=%d\n",rsp_msg_buf->message_arg);
							rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
							if(rc) goto do_show_level_kd_job_fail;
						}
    		
						rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
						if(rc) goto do_show_level_kd_job_fail;
					}			
					
					rc = sm_set_cmd_kd_msg(msg_in,rsp_msg_buf);
					if(rc) goto do_show_level_kd_job_fail;			
					
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
					rc = append_rsp_msg(rsp_msg_buf,"command=show\n",strlen("command=show\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
					rc = append_rsp_msg(rsp_msg_buf,"command=start\n",strlen("command=start\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
					rc = append_rsp_msg(rsp_msg_buf,"command=stop\n",strlen("command=stop\n"));
					if(rc) goto do_show_level_kd_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
					rc = append_rsp_msg(rsp_msg_buf,"command=version\n",strlen("command=version\n"));
					if(rc) goto do_show_level_kd_job_fail;			
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
					rc = append_rsp_msg(rsp_msg_buf,"command=create\n",strlen("command=create\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
					rc = append_rsp_msg(rsp_msg_buf,"command=oemverb\n",strlen("command=oemverb\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}else{
					printf("Verb Cannot Found!\n");
					goto do_show_level_kd_job_fail;
				}
				
				goto free_source;
			}

			if(strlen(rsp_msg_buf->targets)!=0){
				rc = append_rsp_msg(rsp_msg_buf,"begingroup=targets\n",strlen("begingroup=targets\n"));
				if(rc) goto do_show_level_kd_job_fail;
					
				rc = append_rsp_msg(rsp_msg_buf,rsp_msg_buf->targets,strlen(rsp_msg_buf->targets));
				if(rc) goto do_show_level_kd_job_fail;
    		
				rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
				if(rc) goto do_show_level_kd_job_fail;
			}	
		}
			break;
		case 0x1:
#if 0
			begingroup=instance
			ufip=/system1/cpu1
			begingroup=property
				property_name=Family
				property_val=1
			endgroup
			begingroup=targets 
				ufip=/system1/cpu1	
			endgroup
			begingroup=verbs
				verb=show
			endgroup			
			endgroup
			
			begingroup=instance
				property_name=OtherFamilyDescription
				property_val=SuperSlow100
			endgroup
			begingroup=verbs
				verb=show
			endgroup
			endgroup
#endif			
			rc = append_rsp_msg(rsp_msg_buf,"begingroup=instance\n",strlen("begingroup=instance\n"));
			if(rc) goto do_show_level_kd_job_fail;

			if(rsp_msg_buf->ufip != NULL){
				sprintf(tmp_buf,"ufip=%s\n",rsp_msg_buf->ufip);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
			}
			
			if(rsp_msg_buf->ppid != 0){
				tmp_buf2 =  calloc(1024,1);
				if(tmp_buf2 == NULL)
					goto do_show_level_kd_job_fail;
				file_name = calloc(1024,1);
				if(file_name == NULL)
					goto do_show_level_kd_job_fail;
    		
				sprintf(file_name,"/tmp/smash_%d",rsp_msg_buf->ppid);
				fp = fopen(file_name,"r");
    		
				if(fp != NULL){
					rc = append_rsp_msg(rsp_msg_buf,"begingroup=property\n",strlen("begingroup=property\n"));
					if(rc) goto do_show_level_kd_job_fail;					
					
					while(fgets(tmp_buf,1024,fp)){						
						ch_pos=strchr(tmp_buf,'=');
						if(ch_pos == 0){
							break;
						}
						
						*ch_pos = 0;
						sprintf(tmp_buf2,"property_name=%s\n",tmp_buf);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf2,strlen(tmp_buf2));
						if(rc) goto do_show_level_kd_job_fail;
						ch_pos++;
						sprintf(tmp_buf2,"property_val=%s",ch_pos);
						rc = append_rsp_msg(rsp_msg_buf,tmp_buf2,strlen(tmp_buf2));
						if(rc) goto do_show_level_kd_job_fail;
					}
					fclose(fp);
					fp = NULL;
					
					rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
					if(rc) goto do_show_level_kd_job_fail;
				}
			}

			if(rsp_msg_buf->support_verbs != -1){
				rc = append_rsp_msg(rsp_msg_buf,"begingroup=verbs\n",strlen("begingroup=verbs\n"));
				if(rc) goto do_show_level_kd_job_fail;
				memset(tmp_buf,0,1024);
				if(rsp_msg_buf->support_verbs & CD_CMD)
					strcat(tmp_buf,"verb=cd\n");
				if(rsp_msg_buf->support_verbs & SHOW_CMD)
					strcat(tmp_buf,"verb=show\n");
				if(rsp_msg_buf->support_verbs & HELP_CMD)
					strcat(tmp_buf,"verb=help\n");
				if(rsp_msg_buf->support_verbs & VERSION_CMD)
					strcat(tmp_buf,"verb=version\n");
				if(rsp_msg_buf->support_verbs & EXIT_CMD)
					strcat(tmp_buf,"verb=exit\n");
				if(rsp_msg_buf->support_verbs & DELETE_CMD)
					strcat(tmp_buf,"verb=delete\n");
				if(rsp_msg_buf->support_verbs & START_CMD)
					strcat(tmp_buf,"verb=start\n");
				if(rsp_msg_buf->support_verbs & STOP_CMD)
					strcat(tmp_buf,"verb=stop\n");
				if(rsp_msg_buf->support_verbs & RESET_CMD)
					strcat(tmp_buf,"verb=reset\n");
				if(rsp_msg_buf->support_verbs & DUMP_CMD)
					strcat(tmp_buf,"verb=dump\n");
				if(rsp_msg_buf->support_verbs & SET_CMD)
					strcat(tmp_buf,"verb=set\n");
				if(rsp_msg_buf->support_verbs & LOAD_CMD)
					strcat(tmp_buf,"verb=load\n");
				if(rsp_msg_buf->support_verbs & CREATE_CMD)
					strcat(tmp_buf,"verb=create\n");
			
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_show_level_kd_job_fail;
			
				rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
				if(rc) goto do_show_level_kd_job_fail;
			}

			rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
			if(rc) goto do_show_level_kd_job_fail;

			break;
		case 0x2:					
			rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
			if(rc) goto do_show_level_kd_job_fail;
			rc = append_rsp_msg(rsp_msg_buf,"endoutput\n",strlen("endoutput\n"));
			if(rc) goto do_show_level_kd_job_fail;				
			break;
		default:
			printf("Error: Level State Not Support!\n");
			return -1;
	}


free_source:	
	if(tmp_buf)	free(tmp_buf);
	if(tmp_buf2)	free(tmp_buf2);
	if(fp)		fclose(fp);
	return 0;

do_show_level_kd_job_fail:
	if(tmp_buf)	free(tmp_buf);
	if(tmp_buf2)	free(tmp_buf2);
	if(fp)		fclose(fp);
	return -1;	
}




int do_parse_keyword_job(char *msg_in,RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	int rc = -1;
	char *tmp_buf = NULL;

	tmp_buf = (char*)calloc(1024,1);
	if(tmp_buf == NULL) goto do_parse_keyword_job_fail;


	sprintf(tmp_buf,"commandline=%s\n",msg_in);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto do_parse_keyword_job_fail;

	sprintf(tmp_buf,"status=%d\n",rsp_msg_buf->status);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto do_parse_keyword_job_fail;

	sprintf(tmp_buf,"status_tag=%s\n",sm_cmd_status_tag_tbl[rsp_msg_buf->status].status_tag);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto do_parse_keyword_job_fail;

	if(rsp_msg_buf->error != 0){
		sprintf(tmp_buf,"error=%d\n",rsp_msg_buf->error);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;


		for(i=0;i<sizeof(sm_err_tbl)/sizeof(SM_ERROR_TBL);i++){
			if(rsp_msg_buf->error == sm_err_tbl[i].error)
				break;
		}

		sprintf(tmp_buf,"error_tag=%s\n",sm_err_tbl[i].err_tag);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;
	}




	sprintf(tmp_buf,"job_id=%d\n",rsp_msg_buf->job_id);
	rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
	if(rc) goto do_parse_keyword_job_fail;

	if(rsp_msg_buf->errtype != -1){
		sprintf(tmp_buf,"errtype=%d\n",rsp_msg_buf->errtype);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;

		sprintf(tmp_buf,"errtype_desc=%s\n",sm_err_type_tbl[rsp_msg_buf->errtype].err_desc);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;		
	}


	if(rsp_msg_buf->cimstat != -1){

		sprintf(tmp_buf,"cimstat=%d\n",rsp_msg_buf->cimstat);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;

		for(i=0;i<sizeof(sm_cim_status_tbl)/sizeof(SM_CIM_STATUS_TBL);i++){
			if(sm_cim_status_tbl[i].cimstat == rsp_msg_buf->cimstat){
				break;
			}
		}
	
		sprintf(tmp_buf,"cimstat_desc=%s\n",sm_cim_status_tbl[i].cimstat_desc);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;
	}

	if(rsp_msg_buf->severity != EL_SERVERITY_NO_SETTING){
		sprintf(tmp_buf,"severity=%d\n",rsp_msg_buf->severity);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;

		for(i=0;i<sizeof(sm_severity_tbl)/sizeof(SM_SEVERITY_TBL);i++){
			if(sm_severity_tbl[i].sev_num == rsp_msg_buf->severity)
				break;
		}

		sprintf(tmp_buf,"severity_desc=%s\n",sm_severity_tbl[i].sev_desc);
		rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
		if(rc) goto do_parse_keyword_job_fail;
	}

	if(rsp_msg_buf->error != 0){
		if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
			rc = append_rsp_msg(rsp_msg_buf,"command=cd\n",strlen("command=cd\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){			
			rc = append_rsp_msg(rsp_msg_buf,"command=delete\n",strlen("command=delete\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
			
			if(rsp_msg_buf->probcause_num != -1){
				sprintf(tmp_buf,"probcause=%d\n",rsp_msg_buf->probcause_num);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_parse_keyword_job_fail;
				
				sprintf(tmp_buf,"probcause_desc=%s\n",sm_probcause_tbl[rsp_msg_buf->probcause_num].probcause_desc);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_parse_keyword_job_fail;
			}
		
			rc = append_rsp_msg(rsp_msg_buf,"command=dump\n",strlen("command=dump\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){
			rc = append_rsp_msg(rsp_msg_buf,"command=exit\n",strlen("command=exit\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
			rc = append_rsp_msg(rsp_msg_buf,"command=help\n",strlen("command=help\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
			rc = append_rsp_msg(rsp_msg_buf,"command=load\n",strlen("command=load\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
			rc = append_rsp_msg(rsp_msg_buf,"command=reset\n",strlen("command=reset\n"));
			if(rc) goto do_parse_keyword_job_fail;		
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
			

 			if(rsp_msg_buf->probcause_num != -1){
				sprintf(tmp_buf,"probcause=%d\n",rsp_msg_buf->probcause_num);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_parse_keyword_job_fail;
				
				sprintf(tmp_buf,"probcause_desc=%s\n",sm_probcause_tbl[rsp_msg_buf->probcause_num].probcause_desc);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_parse_keyword_job_fail;
			}
	
			if(rsp_msg_buf->recmdaction != NULL){
				sprintf(tmp_buf,"recmdaction=%s\n",rsp_msg_buf->recmdaction);
				rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
				if(rc) goto do_parse_keyword_job_fail;
			}
			
			if(rsp_msg_buf->message_id != -1){
				rc = append_rsp_msg(rsp_msg_buf,"begingroup=message\n",strlen("begingroup=message\n"));
				if(rc) goto do_parse_keyword_job_fail;

				if(rsp_msg_buf->owningentity != NULL){
					sprintf(tmp_buf,"owningentity=%s\n",rsp_msg_buf->owningentity);
					rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
					if(rc) goto do_parse_keyword_job_fail;
				}

				if(rsp_msg_buf->message_id != -1){
					sprintf(tmp_buf,"message_id=%d\n",rsp_msg_buf->message_id);
					rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
					if(rc) goto do_parse_keyword_job_fail;
				}


				if(rsp_msg_buf->message != NULL){
					sprintf(tmp_buf,"message=%s\n",rsp_msg_buf->message);
					rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
					if(rc) goto do_parse_keyword_job_fail;
				}
				
				if(rsp_msg_buf->message_arg != -1){
					sprintf(tmp_buf,"message_arg=%d\n",rsp_msg_buf->message_arg);
					rc = append_rsp_msg(rsp_msg_buf,tmp_buf,strlen(tmp_buf));
					if(rc) goto do_parse_keyword_job_fail;
				}

				rc = append_rsp_msg(rsp_msg_buf,"endgroup\n",strlen("endgroup\n"));
				if(rc) goto do_parse_keyword_job_fail;
			}			
			
			rc = sm_set_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;			
			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
			rc = append_rsp_msg(rsp_msg_buf,"command=show\n",strlen("command=show\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
			rc = append_rsp_msg(rsp_msg_buf,"command=start\n",strlen("command=start\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
			rc = append_rsp_msg(rsp_msg_buf,"command=stop\n",strlen("command=stop\n"));
			if(rc) goto do_parse_keyword_job_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
			rc = append_rsp_msg(rsp_msg_buf,"command=version\n",strlen("command=version\n"));
			if(rc) goto do_parse_keyword_job_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
			rc = append_rsp_msg(rsp_msg_buf,"command=create\n",strlen("command=create\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
			rc = append_rsp_msg(rsp_msg_buf,"command=oemverb\n",strlen("command=oemverb\n"));
			if(rc) goto do_parse_keyword_job_fail;
		}else{
			printf("Verb Cannot Found!\n");
			goto do_parse_keyword_job_fail;
		}
		
		goto free_source;
	}







		if(0 == strcasecmp(rsp_msg_buf->cmd,"cd")){
			rc = sm_cd_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"delete")){
			rc = sm_delete_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"dump")){
			rc = sm_dump_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"exit")){			
			rc = sm_exit_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"help")){
			rc = sm_help_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"load")){
			rc = sm_load_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"reset")){
			rc = sm_reset_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"set")){
			rc = sm_set_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"show")){
			rc = sm_show_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"start")){
			rc = sm_start_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"stop")){
			rc = sm_stop_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;			
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"version")){
			rc = sm_version_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"create")){
			rc = sm_create_cmd_kd_msg(msg_in,rsp_msg_buf);
			if(rc) goto do_parse_keyword_job_fail;
		}else if(0 == strcasecmp(rsp_msg_buf->cmd,"oemverb")){
			printf("Verb oemverb Not Support\n");
			goto do_parse_keyword_job_fail;
		}else{
			printf("Verb Cannot Found!\n");
			goto do_parse_keyword_job_fail;
		}



free_source:
	rc = append_rsp_msg(rsp_msg_buf,"endoutput\n",strlen("endoutput\n"));
	if(tmp_buf) free(tmp_buf);
	return 0;
	
do_parse_keyword_job_fail:
	rc = append_rsp_msg(rsp_msg_buf,"endoutput\n",strlen("endoutput\n"));
	if(tmp_buf) free(tmp_buf);
	return -1;
}



