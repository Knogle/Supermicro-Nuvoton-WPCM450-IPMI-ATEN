#line 3 "lex.yy.c"
#define  YY_INT_ALIGNED short int

#include "smash_clpxml.h"
int chk_valid_opt(int argc, char** argv, char *cmd_name, int tbl_idx, RSP_MSG_BUF_TAG *rsp_msg_buf, int cmd_flag);
int clpxml_msg_init(RSP_MSG_BUF_TAG *rsp_msg_buf);
int rsp_msg_buf_init(RSP_MSG_BUF_TAG *rsp_msg_buf);
void rsp_msg_buf_free(RSP_MSG_BUF_TAG *rsp_msg_buf);






#define FLEX_SCANNER
#define YY_FLEX_MAJOR_VERSION 2
#define YY_FLEX_MINOR_VERSION 5
#define YY_FLEX_SUBMINOR_VERSION 34
#if YY_FLEX_SUBMINOR_VERSION > 0
#define FLEX_BETA
#endif


#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>



#ifndef FLEXINT_H
#define FLEXINT_H


#if defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L


#ifndef __STDC_LIMIT_MACROS
#define __STDC_LIMIT_MACROS 1
#endif

#include <inttypes.h>
typedef int8_t flex_int8_t;
typedef uint8_t flex_uint8_t;
typedef int16_t flex_int16_t;
typedef uint16_t flex_uint16_t;
typedef int32_t flex_int32_t;
typedef uint32_t flex_uint32_t;
#else
typedef signed char flex_int8_t;
typedef short int flex_int16_t;
typedef int flex_int32_t;
typedef unsigned char flex_uint8_t; 
typedef unsigned short int flex_uint16_t;
typedef unsigned int flex_uint32_t;
#endif 

#ifndef INT8_MIN
#define INT8_MIN               (-128)
#endif
#ifndef INT16_MIN
#define INT16_MIN              (-32767-1)
#endif
#ifndef INT32_MIN
#define INT32_MIN              (-2147483647-1)
#endif
#ifndef INT8_MAX
#define INT8_MAX               (127)
#endif
#ifndef INT16_MAX
#define INT16_MAX              (32767)
#endif
#ifndef INT32_MAX
#define INT32_MAX              (2147483647)
#endif
#ifndef UINT8_MAX
#define UINT8_MAX              (255U)
#endif
#ifndef UINT16_MAX
#define UINT16_MAX             (65535U)
#endif
#ifndef UINT32_MAX
#define UINT32_MAX             (4294967295U)
#endif

#endif 

#ifdef __cplusplus

#define YY_USE_CONST

#else	

#if defined (__STDC__)

#define YY_USE_CONST

#endif	
#endif	

#ifdef YY_USE_CONST
#define yyconst const
#else
#define yyconst
#endif

#define YY_NULL 0


#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)


#define BEGIN (yy_start) = 1 + 2 *


#define YY_START (((yy_start) - 1) / 2)
#define YYSTATE YY_START

#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)

#define YY_NEW_FILE yyrestart(yyin  )

#define YY_END_OF_BUFFER_CHAR 0

#ifndef YY_BUF_SIZE
#define YY_BUF_SIZE 16384
#endif


#define YY_STATE_BUF_SIZE   ((YY_BUF_SIZE + 2) * sizeof(yy_state_type))

#ifndef YY_TYPEDEF_YY_BUFFER_STATE
#define YY_TYPEDEF_YY_BUFFER_STATE
typedef struct yy_buffer_state *YY_BUFFER_STATE;
#endif

extern int yyleng;

extern FILE *yyin, *yyout;

#define EOB_ACT_CONTINUE_SCAN 0
#define EOB_ACT_END_OF_FILE 1
#define EOB_ACT_LAST_MATCH 2

    #define YY_LESS_LINENO(n)
    
#define yyless(n) \
	do \
		{ \
 \
        int yyless_macro_arg = (n); \
        YY_LESS_LINENO(yyless_macro_arg);\
		*yy_cp = (yy_hold_char); \
		YY_RESTORE_YY_MORE_OFFSET \
		(yy_c_buf_p) = yy_cp = yy_bp + yyless_macro_arg - YY_MORE_ADJ; \
		YY_DO_BEFORE_ACTION;  \
		} \
	while ( 0 )

#define unput(c) yyunput( c, (yytext_ptr)  )



#ifndef YY_TYPEDEF_YY_SIZE_T
#define YY_TYPEDEF_YY_SIZE_T
typedef size_t yy_size_t;
#endif

#ifndef YY_STRUCT_YY_BUFFER_STATE
#define YY_STRUCT_YY_BUFFER_STATE
struct yy_buffer_state
	{
	FILE *yy_input_file;

	char *yy_ch_buf;		
	char *yy_buf_pos;		


	yy_size_t yy_buf_size;


	int yy_n_chars;


	int yy_is_our_buffer;


	int yy_is_interactive;


	int yy_at_bol;

    int yy_bs_lineno; 
    int yy_bs_column; 
    

	int yy_fill_buffer;

	int yy_buffer_status;

#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1

#define YY_BUFFER_EOF_PENDING 2

	};
#endif 

static size_t yy_buffer_stack_top = 0; 
static size_t yy_buffer_stack_max = 0; 
static YY_BUFFER_STATE * yy_buffer_stack = 0; 


#define YY_CURRENT_BUFFER ( (yy_buffer_stack) \
                          ? (yy_buffer_stack)[(yy_buffer_stack_top)] \
                          : NULL)


#define YY_CURRENT_BUFFER_LVALUE (yy_buffer_stack)[(yy_buffer_stack_top)]

static char yy_hold_char;
static int yy_n_chars;		
int yyleng;

static char *yy_c_buf_p = (char *) 0;
static int yy_init = 0;		
static int yy_start = 0;	


static int yy_did_buffer_switch_on_eof;

void yyrestart (FILE *input_file  );
void yy_switch_to_buffer (YY_BUFFER_STATE new_buffer  );
YY_BUFFER_STATE yy_create_buffer (FILE *file,int size  );
void yy_delete_buffer (YY_BUFFER_STATE b  );
void yy_flush_buffer (YY_BUFFER_STATE b  );
void yypush_buffer_state (YY_BUFFER_STATE new_buffer  );
void yypop_buffer_state (void );

static void yyensure_buffer_stack (void );
static void yy_load_buffer_state (void );
static void yy_init_buffer (YY_BUFFER_STATE b,FILE *file  );

#define YY_FLUSH_BUFFER yy_flush_buffer(YY_CURRENT_BUFFER )

YY_BUFFER_STATE yy_scan_buffer (char *base,yy_size_t size  );
YY_BUFFER_STATE yy_scan_string (yyconst char *yy_str  );
YY_BUFFER_STATE yy_scan_bytes (yyconst char *bytes,int len  );

void *yyalloc (yy_size_t  );
void *yyrealloc (void *,yy_size_t  );
void yyfree (void *  );

#define yy_new_buffer yy_create_buffer

#define yy_set_interactive(is_interactive) \
	{ \
	if ( ! YY_CURRENT_BUFFER ){ \
        yyensure_buffer_stack (); \
		YY_CURRENT_BUFFER_LVALUE =    \
            yy_create_buffer(yyin,YY_BUF_SIZE ); \
	} \
	YY_CURRENT_BUFFER_LVALUE->yy_is_interactive = is_interactive; \
	}

#define yy_set_bol(at_bol) \
	{ \
	if ( ! YY_CURRENT_BUFFER ){\
        yyensure_buffer_stack (); \
		YY_CURRENT_BUFFER_LVALUE =    \
            yy_create_buffer(yyin,YY_BUF_SIZE ); \
	} \
	YY_CURRENT_BUFFER_LVALUE->yy_at_bol = at_bol; \
	}

#define YY_AT_BOL() (YY_CURRENT_BUFFER_LVALUE->yy_at_bol)


typedef unsigned char YY_CHAR;

FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;

typedef int yy_state_type;

extern int yylineno;

int yylineno = 1;

extern char *yytext;
#define yytext_ptr yytext

static yy_state_type yy_get_previous_state (void );
static yy_state_type yy_try_NUL_trans (yy_state_type current_state  );
static int yy_get_next_buffer (void );
static void yy_fatal_error (yyconst char msg[]  );


#define YY_DO_BEFORE_ACTION \
	(yytext_ptr) = yy_bp; \
	yyleng = (size_t) (yy_cp - yy_bp); \
	(yy_hold_char) = *yy_cp; \
	*yy_cp = '\0'; \
	(yy_c_buf_p) = yy_cp;

#define YY_NUM_RULES 12
#define YY_END_OF_BUFFER 13

struct yy_trans_info
	{
	flex_int32_t yy_verify;
	flex_int32_t yy_nxt;
	};
static yyconst flex_int16_t yy_accept[23] =
    {   0,
        0,    0,    0,    0,    0,    0,   13,    9,   11,   10,
        1,    5,    7,    6,    8,    2,    4,    3,   12,    9,
        2,    0
    } ;

static yyconst flex_int32_t yy_ec[256] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    2,    3,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    2,    1,    4,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    5,    6,
        1,    7,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    8,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,

        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
        1,    1,    1,    1,    1
    } ;

static yyconst flex_int32_t yy_meta[9] =
    {   0,
        1,    1,    2,    2,    1,    1,    1,    1
    } ;

static yyconst flex_int16_t yy_base[26] =
    {   0,
        0,    0,    6,    8,    0,    0,   20,   18,   21,   21,
       21,   21,   21,   21,   21,    0,   21,   21,   21,   17,
        0,   21,   12,   14,   16
    } ;

static yyconst flex_int16_t yy_def[26] =
    {   0,
       22,    1,   23,   23,   24,   24,   22,   22,   22,   22,
       22,   22,   22,   22,   22,   25,   22,   22,   22,   22,
       25,    0,   22,   22,   22
    } ;

static yyconst flex_int16_t yy_nxt[30] =
    {   0,
        8,    9,   10,   11,   12,   13,   14,   15,   17,   18,
       17,   18,   16,   16,   19,   19,   21,   20,   20,   22,
        7,   22,   22,   22,   22,   22,   22,   22,   22
    } ;

static yyconst flex_int16_t yy_chk[30] =
    {   0,
        1,    1,    1,    1,    1,    1,    1,    1,    3,    3,
        4,    4,   23,   23,   24,   24,   25,   20,    8,    7,
       22,   22,   22,   22,   22,   22,   22,   22,   22
    } ;

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;

extern int yy_flex_debug;
int yy_flex_debug = 0;


#define REJECT reject_used_but_not_detected
#define yymore() yymore_used_but_not_detected
#define YY_MORE_ADJ 0
#define YY_RESTORE_YY_MORE_OFFSET
char *yytext;
#line 1 "parsecmd.l"
#line 2 "parsecmd.l"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <ftw.h>
#include <libgen.h>
#define REMOVE_TEMP_FILE		

static unsigned int job_id=0;
extern const CMD_USAGE_MSG_TAG cmd_usage_tbl[13];
extern char buf[];
extern char* myptr;
extern char* mylim;

extern void display_history_list();
extern void history_finish();

static int my_yyinput(char* buf, int max);
static void free_resource();

static int do_dump(int , char**);
static int do_exit(int, char**);
static int do_cd(int, char**);
static int do_version(int, char**);
static int do_show(int, char**);
static int do_help(int, char**);
static int do_delete(int, char**);
static int do_start(int, char**);
static int do_stop(int, char**);
static int do_reset(int, char**);
static int do_create(int , char**);
static int do_load(int , char**);
static int do_set(int , char**);
static int do_shell(int , char**);
static int selectdir(const struct dirent *dir);


static void add_arg(const char* xarg);
static void add_simple_arg(const char* xarg);
static void reset_args();
static void do_list_cmd();
static int do_pipe_cmd(int argc, char** argv);
static int do_simple_cmd(int argc, char** argv, int prefd[], int postfd[]);

#undef 	YY_INPUT
#define YY_INPUT(b, r, ms) (r = my_yyinput(b, ms))

char* argbuf[200];
int argcnt = 0;

typedef int (*buildin_cmd_handle)(int, char**);
typedef struct
{
	const char* cmd;
	buildin_cmd_handle handle;
} CMD_ENTRY;

typedef struct ResourceTableType
{
	char *resourcename;
	char *classname;
	char *subclassname;
	char *subinstancename;
	int cmd;
	char *help;
} ResourceTable;



typedef struct _verb_and_option_support{
	char *cmd_name;
	unsigned int support_opt;
}VERB_OPT_TBL_TAG;


const VERB_OPT_TBL_TAG verb_option_tbl[]= {
#if 0	
	{"cd",0x16B},
	{"create",0x16B},
	{"delete",0x1EB},
	{"dump",0x5EB},
	{"exit",0x16A},
	{"help",0x16B},
	{"load",0x1EF},
	{"reset",0x1EB},
	{"set",0x1EB},
	{"show",0xBFB},
	{"start",0x1EB},
	{"stop",0x1EB},
	{"version",0x16B},
#endif
	{"cd",0x14B},
	{"create",0x14B},
	{"delete",0x1CB},
	{"dump",0x5CB},
	{"exit",0x14A},
	{"help",0x14B},
	{"load",0x1CF},
	{"reset",0x1CB},
	{"set",0x1CB},
	{"show",0xBDB},
	{"start",0x1CB},
	{"stop",0x1CB},
	{"version",0x14B},
	{"debug",0xBDB},
	{0,0},
};


ResourceTable St_ResourceTable[] = 
{

    { "smash", NULL, NULL, NULL, 0x001f, "The managed element is the root"},
    { "system", NULL, NULL, NULL, 0x001f, "This target is used to manage system settings and operations"},
    { "pwrmgtsvc", "IPMI_PowerManagementService", NULL, NULL, 0x00ff, "This target is used to power control service"},
    { "logs", NULL, NULL, NULL, 0x001f, "Contains the collection of SEL log Elements"},
    { "chassis", "CIM_Chassis", NULL, NULL, 0x001f, "This target is used to manage the physical chassis"},
    { "fans", NULL, NULL, NULL, 0x001f, "Manage fan sensors"},
    { "voltages", NULL, NULL, NULL, 0x001f, "Manage voltage sensors"},
    { "log", "IPMI_RecordLog", "IPMI_LogRecord", "record", 0x011f, "System Event Log (SEL)"},
    { "record", "IPMI_LogRecord", NULL, NULL, 0x001e, "Contains all the records currently in SEL"},
    { "sensors", "CIM_ComputerSystem", "CIM_Sensor", "sensor", 0x001f, "Contains the collection of sensor Elements"},
    { "sensor", "CIM_Sensor", NULL, NULL, 0x001e, "Contains all the sensor status"},
    { "memory", "Update File", NULL, NULL, 0x021e, "Dump Image File"},
    { "fwimage", "Load File", NULL, NULL, 0x041e, "Load Image File"},
    {0, 0, 0, 0, 0, 0}
};

const CMD_ENTRY buildin_cmd_table[] = 
{
	{"dump", 	do_dump},
	{"exit", 	do_exit},
	{"cd", 		do_cd},
	{"version", do_version},
	{"show", 	do_show},
	{"help", 	do_help},
	{"delete", 	do_delete},
	{"start", 	do_start},
	{"stop", 	do_stop},
	{"reset", 	do_reset},
	{"create", 	do_create},
	{"load", 	do_load},
	{"set", 	do_set},
	{"shell", 	do_shell},
	{0, 0}
};



#line 588 "lex.yy.c"

#define INITIAL 0
#define QUOTE 1
#define SINGQUOTE 2

#ifndef YY_NO_UNISTD_H

#include <unistd.h>
#endif

#ifndef YY_EXTRA_TYPE
#define YY_EXTRA_TYPE void *
#endif

static int yy_init_globals (void );



#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap (void );
#else
extern int yywrap (void );
#endif
#endif

    static void yyunput (int c,char *buf_ptr  );
    
#ifndef yytext_ptr
static void yy_flex_strncpy (char *,yyconst char *,int );
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen (yyconst char * );
#endif

#ifndef YY_NO_INPUT

#ifdef __cplusplus
static int yyinput (void );
#else
static int input (void );
#endif

#endif

#ifndef YY_READ_BUF_SIZE
#define YY_READ_BUF_SIZE 8192
#endif

#ifndef ECHO

#define ECHO fwrite( yytext, yyleng, 1, yyout )
#endif


#ifndef YY_INPUT
#define YY_INPUT(buf,result,max_size) \
	if ( YY_CURRENT_BUFFER_LVALUE->yy_is_interactive ) \
		{ \
		int c = '*'; \
		int n; \
		for ( n = 0; n < max_size && \
			     (c = getc( yyin )) != EOF && c != '\n'; ++n ) \
			buf[n] = (char) c; \
		if ( c == '\n' ) \
			buf[n++] = (char) c; \
		if ( c == EOF && ferror( yyin ) ) \
			YY_FATAL_ERROR( "input in flex scanner failed" ); \
		result = n; \
		} \
	else \
		{ \
		errno=0; \
		while ( (result = fread(buf, 1, max_size, yyin))==0 && ferror(yyin)) \
			{ \
			if( errno != EINTR) \
				{ \
				YY_FATAL_ERROR( "input in flex scanner failed" ); \
				break; \
				} \
			errno=0; \
			clearerr(yyin); \
			} \
		}\
\

#endif


#ifndef yyterminate
#define yyterminate() return YY_NULL
#endif

#ifndef YY_START_STACK_INCR
#define YY_START_STACK_INCR 25
#endif

#ifndef YY_FATAL_ERROR
#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )
#endif



#ifndef YY_DECL
#define YY_DECL_IS_OURS 1

extern int yylex (void);

#define YY_DECL int yylex (void)
#endif 


#ifndef YY_USER_ACTION
#define YY_USER_ACTION
#endif

#ifndef YY_BREAK
#define YY_BREAK break;
#endif

#define YY_RULE_SETUP \
	YY_USER_ACTION


YY_DECL
{
	register yy_state_type yy_current_state;
	register char *yy_cp, *yy_bp;
	register int yy_act;
    
#line 127 "parsecmd.l"


#line 746 "lex.yy.c"

	if ( !(yy_init) )
		{
		(yy_init) = 1;

#ifdef YY_USER_INIT
		YY_USER_INIT;
#endif

		if ( ! (yy_start) )
			(yy_start) = 1;	

		if ( ! yyin )
			yyin = stdin;

		if ( ! yyout )
			yyout = stdout;

		if ( ! YY_CURRENT_BUFFER ) {
			yyensure_buffer_stack ();
			YY_CURRENT_BUFFER_LVALUE =
				yy_create_buffer(yyin,YY_BUF_SIZE );
		}

		yy_load_buffer_state( );
		}

	while ( 1 )		
		{
		yy_cp = (yy_c_buf_p);

		*yy_cp = (yy_hold_char);


		yy_bp = yy_cp;

		yy_current_state = (yy_start);
yy_match:
		do
			{
			register YY_CHAR yy_c = yy_ec[YY_SC_TO_UI(*yy_cp)];
			if ( yy_accept[yy_current_state] )
				{
				(yy_last_accepting_state) = yy_current_state;
				(yy_last_accepting_cpos) = yy_cp;
				}
			while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
				{
				yy_current_state = (int) yy_def[yy_current_state];
				if ( yy_current_state >= 23 )
					yy_c = yy_meta[(unsigned int) yy_c];
				}
			yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
			++yy_cp;
			}
		while ( yy_base[yy_current_state] != 21 );

yy_find_action:
		yy_act = yy_accept[yy_current_state];
		if ( yy_act == 0 )
			{ 
			yy_cp = (yy_last_accepting_cpos);
			yy_current_state = (yy_last_accepting_state);
			yy_act = yy_accept[yy_current_state];
			}

		YY_DO_BEFORE_ACTION;

do_action:	

		switch ( yy_act )
	{ 
			case 0: 
			*yy_cp = (yy_hold_char);
			yy_cp = (yy_last_accepting_cpos);
			yy_current_state = (yy_last_accepting_state);
			goto yy_find_action;

case 1:
YY_RULE_SETUP
#line 129 "parsecmd.l"
{BEGIN QUOTE;}
	YY_BREAK
case 2:
YY_RULE_SETUP
#line 130 "parsecmd.l"
{add_arg(yytext);}
	YY_BREAK
case 3:
YY_RULE_SETUP
#line 131 "parsecmd.l"
{BEGIN 0;}
	YY_BREAK
case 4:
YY_RULE_SETUP
#line 132 "parsecmd.l"
{BEGIN 0; do_list_cmd(); reset_args();}
	YY_BREAK
case 5:
YY_RULE_SETUP
#line 133 "parsecmd.l"
{add_simple_arg(yytext);}
	YY_BREAK
case 6:
YY_RULE_SETUP
#line 134 "parsecmd.l"
{add_simple_arg(yytext);}
	YY_BREAK
case 7:
YY_RULE_SETUP
#line 135 "parsecmd.l"
{add_simple_arg(yytext);}
	YY_BREAK
case 8:
YY_RULE_SETUP
#line 136 "parsecmd.l"
{add_simple_arg(yytext);}
	YY_BREAK
case 9:
YY_RULE_SETUP
#line 137 "parsecmd.l"
{add_arg(yytext);}
	YY_BREAK
case 10:
YY_RULE_SETUP
#line 138 "parsecmd.l"
{do_list_cmd(); reset_args();}
	YY_BREAK
case 11:
YY_RULE_SETUP
#line 139 "parsecmd.l"
;
	YY_BREAK
case 12:
YY_RULE_SETUP
#line 141 "parsecmd.l"
ECHO;
	YY_BREAK
#line 891 "lex.yy.c"
case YY_STATE_EOF(INITIAL):
case YY_STATE_EOF(QUOTE):
case YY_STATE_EOF(SINGQUOTE):
	yyterminate();

	case YY_END_OF_BUFFER:
		{
		int yy_amount_of_matched_text = (int) (yy_cp - (yytext_ptr)) - 1;

		*yy_cp = (yy_hold_char);
		YY_RESTORE_YY_MORE_OFFSET

		if ( YY_CURRENT_BUFFER_LVALUE->yy_buffer_status == YY_BUFFER_NEW )
			{

			(yy_n_chars) = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
			YY_CURRENT_BUFFER_LVALUE->yy_input_file = yyin;
			YY_CURRENT_BUFFER_LVALUE->yy_buffer_status = YY_BUFFER_NORMAL;
			}


		if ( (yy_c_buf_p) <= &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] )
			{ 
			yy_state_type yy_next_state;

			(yy_c_buf_p) = (yytext_ptr) + yy_amount_of_matched_text;

			yy_current_state = yy_get_previous_state(  );



			yy_next_state = yy_try_NUL_trans( yy_current_state );

			yy_bp = (yytext_ptr) + YY_MORE_ADJ;

			if ( yy_next_state )
				{
				yy_cp = ++(yy_c_buf_p);
				yy_current_state = yy_next_state;
				goto yy_match;
				}

			else
				{
				yy_cp = (yy_c_buf_p);
				goto yy_find_action;
				}
			}

		else switch ( yy_get_next_buffer(  ) )
			{
			case EOB_ACT_END_OF_FILE:
				{
				(yy_did_buffer_switch_on_eof) = 0;

				if ( yywrap( ) )
					{

					(yy_c_buf_p) = (yytext_ptr) + YY_MORE_ADJ;

					yy_act = YY_STATE_EOF(YY_START);
					goto do_action;
					}

				else
					{
					if ( ! (yy_did_buffer_switch_on_eof) )
						YY_NEW_FILE;
					}
				break;
				}

			case EOB_ACT_CONTINUE_SCAN:
				(yy_c_buf_p) =
					(yytext_ptr) + yy_amount_of_matched_text;

				yy_current_state = yy_get_previous_state(  );

				yy_cp = (yy_c_buf_p);
				yy_bp = (yytext_ptr) + YY_MORE_ADJ;
				goto yy_match;

			case EOB_ACT_LAST_MATCH:
				(yy_c_buf_p) =
				&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)];

				yy_current_state = yy_get_previous_state(  );

				yy_cp = (yy_c_buf_p);
				yy_bp = (yytext_ptr) + YY_MORE_ADJ;
				goto yy_find_action;
			}
		break;
		}

	default:
		YY_FATAL_ERROR(
			"fatal flex scanner internal error--no action found" );
	} 
		} 
} 


static int yy_get_next_buffer (void)
{
    	register char *dest = YY_CURRENT_BUFFER_LVALUE->yy_ch_buf;
	register char *source = (yytext_ptr);
	register int number_to_move, i;
	int ret_val;

	if ( (yy_c_buf_p) > &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] )
		YY_FATAL_ERROR(
		"fatal flex scanner internal error--end of buffer missed" );

	if ( YY_CURRENT_BUFFER_LVALUE->yy_fill_buffer == 0 )
		{ 
		if ( (yy_c_buf_p) - (yytext_ptr) - YY_MORE_ADJ == 1 )
			{

			return EOB_ACT_END_OF_FILE;
			}

		else
			{

			return EOB_ACT_LAST_MATCH;
			}
		}


	number_to_move = (int) ((yy_c_buf_p) - (yytext_ptr)) - 1;

	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);

	if ( YY_CURRENT_BUFFER_LVALUE->yy_buffer_status == YY_BUFFER_EOF_PENDING )

		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars) = 0;

	else
		{
			int num_to_read =
			YY_CURRENT_BUFFER_LVALUE->yy_buf_size - number_to_move - 1;

		while ( num_to_read <= 0 )
			{ 

			YY_BUFFER_STATE b = YY_CURRENT_BUFFER;

			int yy_c_buf_p_offset =
				(int) ((yy_c_buf_p) - b->yy_ch_buf);

			if ( b->yy_is_our_buffer )
				{
				int new_size = b->yy_buf_size * 2;

				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;

				b->yy_ch_buf = (char *)
					yyrealloc((void *) b->yy_ch_buf,b->yy_buf_size + 2  );
				}
			else
				b->yy_ch_buf = 0;

			if ( ! b->yy_ch_buf )
				YY_FATAL_ERROR(
				"fatal error - scanner input buffer overflow" );

			(yy_c_buf_p) = &b->yy_ch_buf[yy_c_buf_p_offset];

			num_to_read = YY_CURRENT_BUFFER_LVALUE->yy_buf_size -
						number_to_move - 1;

			}

		if ( num_to_read > YY_READ_BUF_SIZE )
			num_to_read = YY_READ_BUF_SIZE;

		YY_INPUT( (&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[number_to_move]),
			(yy_n_chars), (size_t) num_to_read );

		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	if ( (yy_n_chars) == 0 )
		{
		if ( number_to_move == YY_MORE_ADJ )
			{
			ret_val = EOB_ACT_END_OF_FILE;
			yyrestart(yyin  );
			}

		else
			{
			ret_val = EOB_ACT_LAST_MATCH;
			YY_CURRENT_BUFFER_LVALUE->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
			}
		}

	else
		ret_val = EOB_ACT_CONTINUE_SCAN;

	if ((yy_size_t) ((yy_n_chars) + number_to_move) > YY_CURRENT_BUFFER_LVALUE->yy_buf_size) {
		yy_size_t new_size = (yy_n_chars) + number_to_move + ((yy_n_chars) >> 1);
		YY_CURRENT_BUFFER_LVALUE->yy_ch_buf = (char *) yyrealloc((void *) YY_CURRENT_BUFFER_LVALUE->yy_ch_buf,new_size  );
		if ( ! YY_CURRENT_BUFFER_LVALUE->yy_ch_buf )
			YY_FATAL_ERROR( "out of dynamic memory in yy_get_next_buffer()" );
	}

	(yy_n_chars) += number_to_move;
	YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] = YY_END_OF_BUFFER_CHAR;
	YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars) + 1] = YY_END_OF_BUFFER_CHAR;

	(yytext_ptr) = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[0];

	return ret_val;
}


    static yy_state_type yy_get_previous_state (void)
{
	register yy_state_type yy_current_state;
	register char *yy_cp;
    
	yy_current_state = (yy_start);

	for ( yy_cp = (yytext_ptr) + YY_MORE_ADJ; yy_cp < (yy_c_buf_p); ++yy_cp )
		{
		register YY_CHAR yy_c = (*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
			{
			(yy_last_accepting_state) = yy_current_state;
			(yy_last_accepting_cpos) = yy_cp;
			}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
			{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 23 )
				yy_c = yy_meta[(unsigned int) yy_c];
			}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
		}

	return yy_current_state;
}


    static yy_state_type yy_try_NUL_trans  (yy_state_type yy_current_state )
{
	register int yy_is_jam;
    	register char *yy_cp = (yy_c_buf_p);

	register YY_CHAR yy_c = 1;
	if ( yy_accept[yy_current_state] )
		{
		(yy_last_accepting_state) = yy_current_state;
		(yy_last_accepting_cpos) = yy_cp;
		}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 23 )
			yy_c = yy_meta[(unsigned int) yy_c];
		}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 22);

	return yy_is_jam ? 0 : yy_current_state;
}

    static void yyunput (int c, register char * yy_bp )
{
	register char *yy_cp;
    
    yy_cp = (yy_c_buf_p);

	*yy_cp = (yy_hold_char);

	if ( yy_cp < YY_CURRENT_BUFFER_LVALUE->yy_ch_buf + 2 )
		{ 
		register int number_to_move = (yy_n_chars) + 2;
		register char *dest = &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[
					YY_CURRENT_BUFFER_LVALUE->yy_buf_size + 2];
		register char *source =
				&YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[number_to_move];

		while ( source > YY_CURRENT_BUFFER_LVALUE->yy_ch_buf )
			*--dest = *--source;

		yy_cp += (int) (dest - source);
		yy_bp += (int) (dest - source);
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars =
			(yy_n_chars) = YY_CURRENT_BUFFER_LVALUE->yy_buf_size;

		if ( yy_cp < YY_CURRENT_BUFFER_LVALUE->yy_ch_buf + 2 )
			YY_FATAL_ERROR( "flex scanner push-back overflow" );
		}

	*--yy_cp = (char) c;

	(yytext_ptr) = yy_bp;
	(yy_hold_char) = *yy_cp;
	(yy_c_buf_p) = yy_cp;
}

#ifndef YY_NO_INPUT
#ifdef __cplusplus
    static int yyinput (void)
#else
    static int input  (void)
#endif

{
	int c;
    
	*(yy_c_buf_p) = (yy_hold_char);

	if ( *(yy_c_buf_p) == YY_END_OF_BUFFER_CHAR )
		{

		if ( (yy_c_buf_p) < &YY_CURRENT_BUFFER_LVALUE->yy_ch_buf[(yy_n_chars)] )
			*(yy_c_buf_p) = '\0';

		else
			{ 
			int offset = (yy_c_buf_p) - (yytext_ptr);
			++(yy_c_buf_p);

			switch ( yy_get_next_buffer(  ) )
				{
				case EOB_ACT_LAST_MATCH:


					yyrestart(yyin );


				case EOB_ACT_END_OF_FILE:
					{
					if ( yywrap( ) )
						return EOF;

					if ( ! (yy_did_buffer_switch_on_eof) )
						YY_NEW_FILE;
#ifdef __cplusplus
					return yyinput();
#else
					return input();
#endif
					}

				case EOB_ACT_CONTINUE_SCAN:
					(yy_c_buf_p) = (yytext_ptr) + offset;
					break;
				}
			}
		}

	c = *(unsigned char *) (yy_c_buf_p);	
	*(yy_c_buf_p) = '\0';	
	(yy_hold_char) = *++(yy_c_buf_p);

	return c;
}
#endif	


    void yyrestart  (FILE * input_file )
{
    
	if ( ! YY_CURRENT_BUFFER ){
        yyensure_buffer_stack ();
		YY_CURRENT_BUFFER_LVALUE =
            yy_create_buffer(yyin,YY_BUF_SIZE );
	}

	yy_init_buffer(YY_CURRENT_BUFFER,input_file );
	yy_load_buffer_state( );
}


    void yy_switch_to_buffer  (YY_BUFFER_STATE  new_buffer )
{
    

	yyensure_buffer_stack ();
	if ( YY_CURRENT_BUFFER == new_buffer )
		return;

	if ( YY_CURRENT_BUFFER )
		{
		*(yy_c_buf_p) = (yy_hold_char);
		YY_CURRENT_BUFFER_LVALUE->yy_buf_pos = (yy_c_buf_p);
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	YY_CURRENT_BUFFER_LVALUE = new_buffer;
	yy_load_buffer_state( );


	(yy_did_buffer_switch_on_eof) = 1;
}

static void yy_load_buffer_state  (void)
{
    	(yy_n_chars) = YY_CURRENT_BUFFER_LVALUE->yy_n_chars;
	(yytext_ptr) = (yy_c_buf_p) = YY_CURRENT_BUFFER_LVALUE->yy_buf_pos;
	yyin = YY_CURRENT_BUFFER_LVALUE->yy_input_file;
	(yy_hold_char) = *(yy_c_buf_p);
}


    YY_BUFFER_STATE yy_create_buffer  (FILE * file, int  size )
{
	YY_BUFFER_STATE b;
    
	b = (YY_BUFFER_STATE) yyalloc(sizeof( struct yy_buffer_state )  );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_buf_size = size;


	b->yy_ch_buf = (char *) yyalloc(b->yy_buf_size + 2  );
	if ( ! b->yy_ch_buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_create_buffer()" );

	b->yy_is_our_buffer = 1;

	yy_init_buffer(b,file );

	return b;
}


    void yy_delete_buffer (YY_BUFFER_STATE  b )
{
    
	if ( ! b )
		return;

	if ( b == YY_CURRENT_BUFFER ) 
		YY_CURRENT_BUFFER_LVALUE = (YY_BUFFER_STATE) 0;

	if ( b->yy_is_our_buffer )
		yyfree((void *) b->yy_ch_buf  );

	yyfree((void *) b  );
}

#ifndef __cplusplus
extern int isatty (int );
#endif 
    

    static void yy_init_buffer  (YY_BUFFER_STATE  b, FILE * file )

{
	int oerrno = errno;
    
	yy_flush_buffer(b );

	b->yy_input_file = file;
	b->yy_fill_buffer = 1;


    if (b != YY_CURRENT_BUFFER){
        b->yy_bs_lineno = 1;
        b->yy_bs_column = 0;
    }

        b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;
    
	errno = oerrno;
}


    void yy_flush_buffer (YY_BUFFER_STATE  b )
{
    	if ( ! b )
		return;

	b->yy_n_chars = 0;


	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;
	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;

	b->yy_buf_pos = &b->yy_ch_buf[0];

	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;

	if ( b == YY_CURRENT_BUFFER )
		yy_load_buffer_state( );
}


void yypush_buffer_state (YY_BUFFER_STATE new_buffer )
{
    	if (new_buffer == NULL)
		return;

	yyensure_buffer_stack();

	if ( YY_CURRENT_BUFFER )
		{
		*(yy_c_buf_p) = (yy_hold_char);
		YY_CURRENT_BUFFER_LVALUE->yy_buf_pos = (yy_c_buf_p);
		YY_CURRENT_BUFFER_LVALUE->yy_n_chars = (yy_n_chars);
		}

	if (YY_CURRENT_BUFFER)
		(yy_buffer_stack_top)++;
	YY_CURRENT_BUFFER_LVALUE = new_buffer;

	yy_load_buffer_state( );
	(yy_did_buffer_switch_on_eof) = 1;
}


void yypop_buffer_state (void)
{
    	if (!YY_CURRENT_BUFFER)
		return;

	yy_delete_buffer(YY_CURRENT_BUFFER );
	YY_CURRENT_BUFFER_LVALUE = NULL;
	if ((yy_buffer_stack_top) > 0)
		--(yy_buffer_stack_top);

	if (YY_CURRENT_BUFFER) {
		yy_load_buffer_state( );
		(yy_did_buffer_switch_on_eof) = 1;
	}
}


static void yyensure_buffer_stack (void)
{
	int num_to_alloc;
    
	if (!(yy_buffer_stack)) {


		num_to_alloc = 1;
		(yy_buffer_stack) = (struct yy_buffer_state**)yyalloc
								(num_to_alloc * sizeof(struct yy_buffer_state*)
								);
		if ( ! (yy_buffer_stack) )
			YY_FATAL_ERROR( "out of dynamic memory in yyensure_buffer_stack()" );
								  
		memset((yy_buffer_stack), 0, num_to_alloc * sizeof(struct yy_buffer_state*));
				
		(yy_buffer_stack_max) = num_to_alloc;
		(yy_buffer_stack_top) = 0;
		return;
	}

	if ((yy_buffer_stack_top) >= ((yy_buffer_stack_max)) - 1){

		int grow_size = 8 ;

		num_to_alloc = (yy_buffer_stack_max) + grow_size;
		(yy_buffer_stack) = (struct yy_buffer_state**)yyrealloc
								((yy_buffer_stack),
								num_to_alloc * sizeof(struct yy_buffer_state*)
								);
		if ( ! (yy_buffer_stack) )
			YY_FATAL_ERROR( "out of dynamic memory in yyensure_buffer_stack()" );

		memset((yy_buffer_stack) + (yy_buffer_stack_max), 0, grow_size * sizeof(struct yy_buffer_state*));
		(yy_buffer_stack_max) = num_to_alloc;
	}
}


YY_BUFFER_STATE yy_scan_buffer  (char * base, yy_size_t  size )
{
	YY_BUFFER_STATE b;
    
	if ( size < 2 ||
	     base[size-2] != YY_END_OF_BUFFER_CHAR ||
	     base[size-1] != YY_END_OF_BUFFER_CHAR )
		return 0;

	b = (YY_BUFFER_STATE) yyalloc(sizeof( struct yy_buffer_state )  );
	if ( ! b )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_buffer()" );

	b->yy_buf_size = size - 2;	
	b->yy_buf_pos = b->yy_ch_buf = base;
	b->yy_is_our_buffer = 0;
	b->yy_input_file = 0;
	b->yy_n_chars = b->yy_buf_size;
	b->yy_is_interactive = 0;
	b->yy_at_bol = 1;
	b->yy_fill_buffer = 0;
	b->yy_buffer_status = YY_BUFFER_NEW;

	yy_switch_to_buffer(b  );

	return b;
}


YY_BUFFER_STATE yy_scan_string (yyconst char * yystr )
{
    
	return yy_scan_bytes(yystr,strlen(yystr) );
}


YY_BUFFER_STATE yy_scan_bytes  (yyconst char * yybytes, int  _yybytes_len )
{
	YY_BUFFER_STATE b;
	char *buf;
	yy_size_t n;
	int i;
    
	n = _yybytes_len + 2;
	buf = (char *) yyalloc(n  );
	if ( ! buf )
		YY_FATAL_ERROR( "out of dynamic memory in yy_scan_bytes()" );

	for ( i = 0; i < _yybytes_len; ++i )
		buf[i] = yybytes[i];

	buf[_yybytes_len] = buf[_yybytes_len+1] = YY_END_OF_BUFFER_CHAR;

	b = yy_scan_buffer(buf,n );
	if ( ! b )
		YY_FATAL_ERROR( "bad buffer in yy_scan_bytes()" );


	b->yy_is_our_buffer = 1;

	return b;
}

#ifndef YY_EXIT_FAILURE
#define YY_EXIT_FAILURE 2
#endif

static void yy_fatal_error (yyconst char* msg )
{
    	(void) fprintf( stderr, "%s\n", msg );
	exit( YY_EXIT_FAILURE );
}


#undef yyless
#define yyless(n) \
	do \
		{ \
 \
        int yyless_macro_arg = (n); \
        YY_LESS_LINENO(yyless_macro_arg);\
		yytext[yyleng] = (yy_hold_char); \
		(yy_c_buf_p) = yytext + yyless_macro_arg; \
		(yy_hold_char) = *(yy_c_buf_p); \
		*(yy_c_buf_p) = '\0'; \
		yyleng = yyless_macro_arg; \
		} \
	while ( 0 )



int yyget_lineno  (void)
{
        
    return yylineno;
}


FILE *yyget_in  (void)
{
        return yyin;
}


FILE *yyget_out  (void)
{
        return yyout;
}


int yyget_leng  (void)
{
        return yyleng;
}



char *yyget_text  (void)
{
        return yytext;
}


void yyset_lineno (int  line_number )
{
    
    yylineno = line_number;
}


void yyset_in (FILE *  in_str )
{
        yyin = in_str ;
}

void yyset_out (FILE *  out_str )
{
        yyout = out_str ;
}

int yyget_debug  (void)
{
        return yy_flex_debug;
}

void yyset_debug (int  bdebug )
{
        yy_flex_debug = bdebug ;
}

static int yy_init_globals (void)
{


    (yy_buffer_stack) = 0;
    (yy_buffer_stack_top) = 0;
    (yy_buffer_stack_max) = 0;
    (yy_c_buf_p) = (char *) 0;
    (yy_init) = 0;
    (yy_start) = 0;

#ifdef YY_STDINIT
    yyin = stdin;
    yyout = stdout;
#else
    yyin = (FILE *) 0;
    yyout = (FILE *) 0;
#endif


    return 0;
}

int yylex_destroy  (void)
{
    
	while(YY_CURRENT_BUFFER){
		yy_delete_buffer(YY_CURRENT_BUFFER  );
		YY_CURRENT_BUFFER_LVALUE = NULL;
		yypop_buffer_state();
	}

	yyfree((yy_buffer_stack) );
	(yy_buffer_stack) = NULL;


    yy_init_globals( );

    return 0;
}



#ifndef yytext_ptr
static void yy_flex_strncpy (char* s1, yyconst char * s2, int n )
{
	register int i;
	for ( i = 0; i < n; ++i )
		s1[i] = s2[i];
}
#endif

#ifdef YY_NEED_STRLEN
static int yy_flex_strlen (yyconst char * s )
{
	register int n;
	for ( n = 0; s[n]; ++n )
		;

	return n;
}
#endif

void *yyalloc (yy_size_t  size )
{
	return (void *) malloc( size );
}

void *yyrealloc  (void * ptr, yy_size_t  size )
{

	return (void *) realloc( (char *) ptr, size );
}

void yyfree (void * ptr )
{
	free( (char *) ptr );	
}

#define YYTABLES_NAME "yytables"

#line 141 "parsecmd.l"



inline char* strlwr( char* str )
{
   char* orig = str;
   return orig;
}

int cmd_check(char *bname, int cmd)
{
	int i=0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, bname) == 0)
			break;
		i++;
	}
	if (0 == St_ResourceTable[i].resourcename)
	{
		printf("Undefine resource... \n");	
	}
	
	if (cmd & St_ResourceTable[i].cmd)
		return 1;
	else
		return 0;
}

int buildfs(const char *file, const struct stat *sb,int flag)
{
	char bname[255];
	char UFcT[255];
	int i;
	char *number;
	sprintf(bname,"%s",basename(file));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';
	number=index(bname,bname[i]);
	
	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}
	
	if(NULL != St_ResourceTable[i].subclassname)
	{
		if (fork()==0)
		{
			if (-1 == execl("/SMASH/buildFS","buildFS",St_ResourceTable[i].subclassname,number,St_ResourceTable[i].subinstancename,file,(char *)0))
			{
				printf("1:%s \n",strerror(errno));
				exit(0);
			}
		}
		wait(NULL);
	}	
	
	return 0;
}

static buildin_cmd_handle get_cmd_handle(const char* cmd)
{
	int i = 0;
	while(buildin_cmd_table[i].cmd) {
		if(strcasecmp(buildin_cmd_table[i].cmd, cmd) == 0)
			return buildin_cmd_table[i].handle;
		i++;
	}
	return 0;
}
static void free_resource()
{
	reset_args();
}

static int do_load(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"load")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find load -help command\n");
			goto free_source;
		}
	}


	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"load")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,LOAD_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}

	for(i=1 ; i<argc ; i++)
	{

		if(NULL != argv[i])
		if( 0 == strcasecmp(argv[i],"-source") ){
			rsp_msg_buf.option |= SMASH_OPT_SOURCE;
			argv[i]=NULL;
			
			if(NULL != argv[i+1]){
				rsp_msg_buf.src_addr = calloc(strlen(argv[i+1]),1);
				if(rsp_msg_buf.src_addr == NULL)
					goto job_fail;

				memcpy(rsp_msg_buf.src_addr,argv[i+1],strlen(argv[i+1]));
				printf("source address is %s\n",rsp_msg_buf.src_addr);
				argv[i+1] = NULL;
			}else{
				printf("Cannot find the source address!\n");
				goto job_fail;
			}
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,LOAD_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	
job_done:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;		
}

static int do_set(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"set")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find set -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"set")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,SET_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,SET_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	else
	{
		if(rsp_msg_buf.out_fmt==0)
			printf("set done... \n");
	}
	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;		
}

static int do_create(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;

	memset(target,0,sizeof(target));

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"create")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find create -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"create")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,CREATE_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	if(strlen(target)==0){
		printf("Command need a valid target!\n");
		goto job_fail;
	}
	
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,CREATE_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");	
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;		
}


static int do_shell(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char buffer[255];
	char *p = NULL;
	char *k = NULL;

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	

	if(job_id == MAX_JOBID_NUM) job_id=0;
		rsp_msg_buf.job_id = ++job_id;
	if (argc != 2 )
	{
		printf("Incorrect command format!\n");
		goto free_source;	
	}	
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);
		
	chdir("/");
	sprintf (buffer,"/bin/%s",argv[1]);
	printf ("Change shell to %s\n",argv[1]);
	if ( fork() == 0 )
	{
		if ( execlp(buffer,argv[1],(char *)0) < 0 )
		{
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			perror ("changing shell fails.");
			goto free_source;
		}
	}
	wait(NULL);
	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;		
}


static int do_dump(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"dump")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find dump -help command\n");
			goto free_source;
		}
	}


	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"dump")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,DUMP_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}

	for(i=1 ; i<argc ; i++)
	{

		if(NULL != argv[i])
		if( 0 == strcasecmp(argv[i],"-destination") ){
			rsp_msg_buf.option |= SMASH_OPT_DESTINATION;
			argv[i]=NULL;
			
			if(NULL != argv[i+1]){

				rsp_msg_buf.dst_addr = calloc(strlen(argv[i+1]),1);
				if(rsp_msg_buf.dst_addr == NULL)
					goto job_fail;

				memcpy(rsp_msg_buf.dst_addr,argv[i+1],strlen(argv[i+1]));
				printf("destination address is %s\n",rsp_msg_buf.dst_addr);
				argv[i+1] = NULL;
			}else{
				printf("Cannot find the destination address!\n");
				goto job_fail;
			}
		}
	}


	if( (rsp_msg_buf.option & SMASH_OPT_DESTINATION) == 0 ){
		if(rsp_msg_buf.out_fmt==0){
			printf("Dump command requires a destination option that was not supplied.\n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 245;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 6;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}

	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,DUMP_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}

	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;		
}

static int do_exit(int argc, char** argv)
{

	int val = 0;
	int rc = -1;
	int tbl_idx=0;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i=0;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	if(argc > 1)
		val = atoi(argv[1]);

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(0 == strcasecmp(argv[i],"format=clpxml")){
					argv[i] = NULL;
					rsp_msg_buf.out_fmt = 1;
					break;
				}else if(0 == strcasecmp(argv[i],"format=keyword")){
					argv[i] = NULL;
					rsp_msg_buf.out_fmt = 2;
					break;
				}else{
					printf("output option don't support the format!\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"exit")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_check;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find exit -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"exit")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,EXIT_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}

job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
	return 0;
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);

	free_resource();
	history_finish();
	exit(val);
	return 0;

job_check:
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;		

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	

	return -1;
}

static int do_cd(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *number = NULL;
	char *p = NULL;
	char *k = NULL;


	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

		for(i=1;i<argc;i++){
			if(NULL != argv[i]){
				if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
				{
					argv[i]=NULL;
					if(NULL != argv[++i])
					{
						if(0 == strcasecmp(argv[i],"format=clpxml")){
							argv[i] = NULL;
							rsp_msg_buf.out_fmt = 1;
							break;
						}else if(0 == strcasecmp(argv[i],"format=keyword")){
							argv[i] = NULL;
							rsp_msg_buf.out_fmt = 2;
							break;
						}else{
							printf("output option don't support the format!\n");
							goto free_source;
						}
					}else{
						printf("output option need an argumtn !\n");
						goto free_source;
					}
				}
			}			
		}

	if(argc >= 2)
	{
		for(i=1 ; i<argc ; i++)
		{
			if(NULL != argv[i])
			if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
			{
				argv[i]=NULL;
            	
				for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
					if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"cd")){
						if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
							if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
								rsp_msg_buf.status = CMD_ST_PROC_FAILED;
								rsp_msg_buf.error = 252;
							}
							rsp_msg_buf.option |= SMASH_OPT_HELP;
							goto job_done;
						}
						
						if(rsp_msg_buf.out_fmt==0){
						if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
							printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
						printf("%s\n\n\n",cmdline);
						if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
							printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
						}
						
						goto free_source;
					}
				}
				printf("Error: Cannot find cd -help command\n");
				goto free_source;				
			}
		}
		  	
		for(i=1 ; i<argc ; i++){
			if(NULL != argv[i])
			if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
				argv[i] = NULL;
				for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
					if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"cd")==0){
						rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
						rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,CD_CMD);
						if(rc){
							printf("command format not right!\n");
							goto free_source;
						}else{
							break;
						}
					}
				}
				break;
			}
		}		
		
		for(i=1 ; i<argc ; i++)
		{
			if(NULL != argv[i])
			if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
			{
				argv[i]=NULL;
				if(rsp_msg_buf.out_fmt == 0)
					printf("Version 1.00\n");
				goto free_source;				
			}
		}
		
 	
		for(i=1 ; i<argc ; i++)
		{
			if(NULL != argv[i])
			if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
			}
		}
		
		for(i=1 ; i<argc ; i++)
		{
			if(NULL != argv[i])
			{
				argv[i] = strlwr(argv[i]);
				if('/' == argv[i][0])
					sprintf(target,"/tmp/smash%s",argv[i]);
				else
					sprintf(target,"%s",argv[i]);
				if( -1 == chdir(target))
				{
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
						rsp_msg_buf.error = 242;
						rsp_msg_buf.errtype = 1;
						rsp_msg_buf.cimstat = 6;
						rsp_msg_buf.severity = Low;
						goto job_fail;
					}
					
					printf("Invalid Targets!.\n");
					goto job_fail;
				}else{
					argv[i] = NULL;
				}
				break;
			}
		}		
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}	
		
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}

		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");			
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';
	number=index(bname,bname[i]);


	if (0 == cmd_check(UFcT,CD_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		chdir(path);
		goto job_fail;
	}

	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){	
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN 
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(k) 		free(k);	
	return -1;
}

int do_version(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;
	
	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);	

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;
	
	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"version")){
					rsp_msg_buf.option |= SMASH_OPT_HELP;
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						break;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			if( (rsp_msg_buf.option & SMASH_OPT_HELP)==0 ){
				printf("Error: Cannot find version -help command\n");
				goto free_source;
			}
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"version")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,VERSION_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
				if(rsp_msg_buf.out_fmt == 0)
					printf("Version 1.00\n");
				goto free_source;
			}
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Invalid syntax; the version command does not support a target.");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	

	
job_done:
	if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
		if(rsp_msg_buf.out_fmt==0)
			printf("ATEN SMASH CLP Shell Version 1.00 \n");
	}else{
		if(rsp_msg_buf.out_fmt==0)
			printf("valid command format!\n");
	}
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){	
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;	
}


int do_start(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;
	

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"start")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find start -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"start")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,START_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);

			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';
	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,START_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
				rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
				rsp_msg_buf.error = 242;
				rsp_msg_buf.errtype = 1;
				rsp_msg_buf.cimstat = 7;
				rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
			if (fork()==0)
			{
				if (-1 == execl("/SMASH/start","start",St_ResourceTable[i].classname, "StartService",(char *)0))
				{
					printf("Error: EXCE_START\n");
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					printf("1:%s \n",strerror(errno));
					goto free_source;
				}
			}
			wait(NULL);
			if(rsp_msg_buf.out_fmt==0)
				printf("start done... \n");
		}
	}
	
job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}


	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;
}


int do_stop(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;	
	
	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);
	
	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;	
	
	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"stop")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find stop -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;			
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"stop")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,STOP_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
		
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}	
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,STOP_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){		
			if (fork()==0)
			{
				if (-1 == execl("/SMASH/stop","stop",St_ResourceTable[i].classname, "StopService",(char *)0))
				{
					printf("Error: EXCE_STOP\n");
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					printf("1:%s \n",strerror(errno));
					goto free_source;
        	
				}
			}
			wait(NULL);
			if(rsp_msg_buf.out_fmt==0)
				printf("stop done... \n");	
		}
	}

	
job_done:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;
}

int do_reset(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;
	

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"reset")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find reset -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"reset")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,RESET_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}else{
				argv[i] = NULL;
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			if(rsp_msg_buf.out_fmt==0){
				printf("Syntax Error!\n");
				goto free_source;
			}else{
				rsp_msg_buf.status = CMD_ST_PROC_FAILED;
				rsp_msg_buf.error = 252;
				goto job_fail;
			}
		}
	}
	
	
	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,RESET_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
			if (fork()==0)
			{
				if (-1 == execl("/SMASH/reset","reset",St_ResourceTable[i].classname, "ResetService",(char *)0))
				{
					printf("Error: EXCE_RESET\n");
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					printf("1:%s \n",strerror(errno));
					goto free_source;
				}
			}
			wait(NULL);		
			if(rsp_msg_buf.out_fmt==0)
				printf("reset done... \n");	
		}
	}

job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;
}

int do_delete(int argc, char** argv)
{	
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i;
	int verbs = 0;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *p = NULL;
	char *k = NULL;
	char kill[30];
	

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"delete")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find delete -help command\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"delete")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,DELETE_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}	
	}
	
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			p = strrchr(argv[i],'/'); 
			if(NULL == p)
			{
				sprintf(target,".");
				strcpy(kill,argv[i]);
			}
			else
			{
				strcpy(kill,p+1);
				*p = '\0';
				if('/' == argv[i][0])
					sprintf(target,"/tmp/smash%s",argv[i]);
				else
					sprintf(target,"%s",argv[i]);
			}	
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}
			break;
		}
	}	

	if(strlen(target)==0){
		printf("Command need a valid target!\n");
		goto job_fail;
	}


	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");	
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';

	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,DELETE_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	else
	{
		if(0 == strcasecmp(kill,"record*"))
		{
			if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
				pid_t pid = getpid();
				sprintf(pid_str,"pid=%d",pid);
				rsp_msg_buf.ppid = (int)pid;
				if (fork()==0)
				{
					if (-1 == execl("/SMASH/deletemethod","deletemethod",St_ResourceTable[i].classname, "clearlog",(char *)0))
					{
						printf("Error: EXCE_Delete\n");
						rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
						printf("1:%s \n",strerror(errno));
						goto free_source;
					}
				}
				wait(NULL);	
				if(rsp_msg_buf.out_fmt==0)	
					printf("Delete %s done... \n",kill);	
			}
		}
		else
		{
			if(rsp_msg_buf.out_fmt==0)
			{
				printf("Invalid target! Only support delete all of the logs: \n");
				printf("please use \"delete record*\" \n");
			}
		}
	}

job_done:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;

		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
		
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return 0;

job_fail:	
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);	
	return -1;	
}

int selectdir(const struct dirent *dir)
{
	if(0 == strcasecmp(dir->d_name,".") || 0 == strcasecmp(dir->d_name,".."))
		return 0;
	else
		return 1;
}

int do_help(int argc, char** argv)
{
	int i;
	int tbl_idx;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	char *path;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *number;
	char *cmdline;
	int  rc = -1;
	char *k = NULL;
	char *p = NULL;
	
	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}
	
	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));
	
	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				rsp_msg_buf.option |= SMASH_OPT_HELP;
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"help")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						break;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			if( (rsp_msg_buf.option& SMASH_OPT_HELP)==0 ){
				printf("Error: Cannot find help -help command\n");
				goto free_source;
			}
		}
	}

	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"help")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,HELP_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;			
			printf("Version 1.00\n");
			return 0;
		}
	}

	if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i]){		
			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,argv[i])){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;			
						rsp_msg_buf.cmd_help_msg = (char*)calloc(strlen(argv[i]),1);
						memcpy(rsp_msg_buf.cmd_help_msg,argv[i],strlen(argv[i]));
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
						printf("%s\n\n\n",cmdline);
						if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
							printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}			
					goto free_source;
				}
			}
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;		
			}
			break;
		}
	}

	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	
	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';
	number=index(bname,bname[i]);
		
	i = 0;
	while(St_ResourceTable[i].resourcename) 
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}

	if (0 == cmd_check(UFcT,HELP_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}

	if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
	if(rsp_msg_buf.out_fmt==0){
		printf("\n  %s\n",St_ResourceTable[i].help);

		printf("\n  Verbs :\n");
		if(St_ResourceTable[i].cmd & CD_CMD)
			printf("	cd\n");
		if(St_ResourceTable[i].cmd & SHOW_CMD)
			printf("	show\n");
		if(St_ResourceTable[i].cmd & HELP_CMD)
			printf("	help\n");
		if(St_ResourceTable[i].cmd & VERSION_CMD)
			printf("	version\n");
		if(St_ResourceTable[i].cmd & EXIT_CMD)
			printf("	exit\n");
		if(St_ResourceTable[i].cmd & DELETE_CMD)
			printf("	delete\n");
		if(St_ResourceTable[i].cmd & START_CMD)
			printf("	start\n");
		if(St_ResourceTable[i].cmd & STOP_CMD)
			printf("	stop\n");
		if(St_ResourceTable[i].cmd & RESET_CMD)
			printf("	reset\n");
		printf("\n");
	}

	if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2))
		rsp_msg_buf.support_verbs = St_ResourceTable[i].cmd;

	
job_done:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){	
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;

		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k)		free(k);
	return 0;

job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){		
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k)		free(k);
	
	return -1;

free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(cmdline)	free(cmdline);
	if(k)		free(k);
	chdir(path);	
	return -1;
}


int do_show(int argc, char** argv)
{
	int rc = -1;
	int tbl_idx;
	char *ch_pos = NULL;	
	char pid_str[16];
	char *cmdline = NULL;
	RSP_MSG_BUF_TAG rsp_msg_buf;
	int i, total;
	int verbs = 0;
	int targets = 0;
	int properties = 0;
	int displayall= 1;
	char *path = NULL;
	char bname[255];
	char UFcT[255];
	char target[255];
	char *number;
	char *p = NULL;
	char *k = NULL;
	struct dirent **namelist;
	int show_level = 0;
	char *tmp_buf = NULL;
	char *fp = NULL;

	memset(target,0,sizeof(target));

	cmdline = calloc(255,1);
	if(cmdline == NULL){
		printf("1:Don't have enough memeory!\n");
		goto free_source;
	}
	
	for(i=0;i<argc;i++){
		strncat(cmdline,argv[i],strlen(argv[i]));
		if(i!= argc-1)
			strncat(cmdline," ",1);
	}

	rc = rsp_msg_buf_init(&rsp_msg_buf);
	if(rc){
		printf("2:Don't have enough memeory!\n");
		goto free_source;
	}

	rsp_msg_buf.cmd = calloc(strlen(argv[0]),1);
	if(rsp_msg_buf.cmd==NULL){
		printf("3:Don't have enough memeory!\n");
		goto free_source;
	}
	memcpy(rsp_msg_buf.cmd,argv[0],strlen(argv[0]));

	rsp_msg_buf.targets = calloc(MAX_TARGES_ARRAT_SZ,1);
	if(rsp_msg_buf.targets == NULL){
		printf("Allocat Targets Array Failed\n");
		goto free_source;
	}


	ftw("/tmp/smash",buildfs,0);
	path = getcwd(NULL,0);

	if(job_id == MAX_JOBID_NUM) job_id=0;
	rsp_msg_buf.job_id = ++job_id;

	for(i=1;i<argc;i++){
		if(NULL != argv[i]){
			if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output"))
			{
				argv[i]=NULL;
				if(NULL != argv[++i])
				{
					if(0 == strcasecmp(argv[i],"format=clpxml")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 1;
						break;
					}else if(0 == strcasecmp(argv[i],"format=keyword")){
						argv[i] = NULL;
						rsp_msg_buf.out_fmt = 2;
						break;
					}else{
						printf("output option don't support the format!\n");
						goto free_source;
					}
				}else{
					printf("output option need an argumtn !\n");
					goto free_source;
				}
			}
		}			
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help"))
		{
			argv[i]=NULL;

			for(tbl_idx=0;tbl_idx<sizeof(cmd_usage_tbl)/sizeof(CMD_USAGE_MSG_TAG);tbl_idx++){
				if(0 == strcasecmp(cmd_usage_tbl[tbl_idx].cmd_name,"show")){
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
						if(cmd_usage_tbl[tbl_idx].usage_msg == NULL){
							rsp_msg_buf.status = CMD_ST_PROC_FAILED;
							rsp_msg_buf.error = 252;
						}
						rsp_msg_buf.option |= SMASH_OPT_HELP;
						goto job_done;
					}
					
					if(rsp_msg_buf.out_fmt==0){
					if(cmd_usage_tbl[tbl_idx].cmd_state != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].cmd_state);
					printf("%s\n\n\n",cmdline);
					if(cmd_usage_tbl[tbl_idx].usage_msg != NULL)
						printf("%s",cmd_usage_tbl[tbl_idx].usage_msg);
					}
					
					goto free_source;
				}
			}
			printf("Error: Cannot find show -help command\n");
			goto free_source;
		}
	}


	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
			argv[i] = NULL;
			for(tbl_idx=0;tbl_idx<sizeof(verb_option_tbl)/sizeof(VERB_OPT_TBL_TAG);tbl_idx++){
				if(strcasecmp(verb_option_tbl[tbl_idx].cmd_name,"show")==0){
					rsp_msg_buf.option |= SMASH_OPT_EXAMINE;
					rc = chk_valid_opt(argc,argv,verb_option_tbl[tbl_idx].cmd_name,tbl_idx,&rsp_msg_buf,SHOW_CMD);
					if(rc){
						printf("command format not right!\n");
						goto free_source;
					}else{
						rsp_msg_buf.status = CMD_ST_COMPLETED;
						break;
					}
				}
			}
			break;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version"))
		{
			argv[i]=NULL;
			if(rsp_msg_buf.out_fmt == 0)
				printf("Version 1.00\n");
			goto free_source;
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force"))
			argv[i]=NULL;
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
			rsp_msg_buf.option |= SMASH_OPT_WAIT;
			argv[i]=NULL;
		}
	}
	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-d") || 0 == strcasecmp(argv[i],"-display"))
		{
			argv[i]=NULL;
			if(NULL != argv[i+1])
			{
				displayall = 0;
				if(0 == strcasecmp(argv[i+1],"verbs"))
					verbs=1;
				else if(0 == strcasecmp(argv[i+1],"targets"))
					targets=1;
				else if(0 == strcasecmp(argv[i+1],"properties"))
					properties=1;
				else if(0 == strcasecmp(argv[i+1],"all"))
					displayall=1;
				else
				{
					printf("Display arguments error\n");
					goto free_source;
				}
				argv[i+1]=NULL;
			}
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-l") || 0 == strcasecmp(argv[i],"-level"))
		{
			rsp_msg_buf.option |= SMASH_OPT_LEVEL;
			argv[i]=NULL;
			if(NULL != argv[i+1])
			{
				if(0 == strcasecmp(argv[i+1],"all"))
					show_level = 0;
				else if( (0<atoi(argv[i+1])) ){
					show_level = atoi(argv[i+1]);
				}
				else
				{
					printf("Level arguments error\n");
					goto free_source;
				}
				argv[i+1]=NULL;
			}
		}
	}

	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		if(0 == strcasecmp(argv[i],"-a") || 0 == strcasecmp(argv[i],"-all"))
		{
			argv[i]=NULL;
		}
	}

	
	for(i=1 ; i<argc ; i++)
	{
		if(NULL != argv[i])
		{
			argv[i] = strlwr(argv[i]);
			if('/' == argv[i][0])
				sprintf(target,"/tmp/smash%s",argv[i]);
			else
				sprintf(target,"%s",argv[i]);
			if( -1 == chdir(target))
			{
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 6;
					rsp_msg_buf.severity = Low;
					goto job_fail;
				}
				printf("Invalid Targets!.\n");
				goto job_fail;
			}
			break;
		}
	}


if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	
	if(strlen(target)==0){
		if(getcwd(target,sizeof(target))==NULL){
			printf("Error: Cannot Find the Target!\n");
			goto job_fail;
		}	
	}
	
	if(rsp_msg_buf.option & SMASH_OPT_LEVEL){
		tmp_buf = calloc(1024,1);
		if(tmp_buf == NULL){
			printf("Error: Allocate mem failed!\n");
			goto free_source;
		}
		if(show_level){
			sprintf(tmp_buf,"/SMASH/tree %s -f -i -L %d --noreport -o /tmp/ftree_%d_%d\n",target,show_level,getpid(),job_id);
		}else{
			sprintf(tmp_buf,"/SMASH/tree %s -f -i --noreport -o /tmp/ftree_%d_%d\n",target,getpid(),job_id);
		}
		system(tmp_buf);

		sprintf(tmp_buf,"/tmp/ftree_%d_%d",getpid(),job_id);
		fp = fopen(tmp_buf,"r");
#ifdef LEX_DBG_EN
printf("file name is : %s\n",tmp_buf);
#endif
		if(fp == NULL){
			printf("Open Tree File Failed!\n");
			goto free_source;
		}
		memset(tmp_buf,0,1024);

		while(fgets(tmp_buf,1024,fp)){
			tmp_buf[strlen(tmp_buf)-1] = 0;
			p = strstr(tmp_buf,"/tmp/smash");

			if (NULL == p)
			{
				chdir(path);
				printf("Invalid Targets!.\n");
				chdir(path);
				goto job_fail;
			}
			else
			{
				if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
				if(rsp_msg_buf.out_fmt==0){
					p = strstr(tmp_buf,"/system1");
					if (NULL == p){
						printf("/ \n");
					}
					else{
						printf("%s\n",p);
					}
				}
						
				if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
					p = strstr(tmp_buf,"/system1");
					if (NULL == p){
						rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
						if(rsp_msg_buf.ufip == NULL){
							printf("5:Don't have enough memeory!\n");
							goto free_source;
						}
						memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
					}
					else{
						rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
						if(rsp_msg_buf.ufip == NULL){
							printf("6:Don't have enough memeory!\n");
							goto free_source;
						}
						memcpy(rsp_msg_buf.ufip,p,strlen(p));
					}
				}
			}
        	
			sprintf(bname,"%s",basename(tmp_buf));
			for(i=0; isdigit(bname[i])== 0; i++)
			{
				UFcT[i] = bname[i];
			}
			UFcT[i]='\0';
			number=index(bname,bname[i]);


			if (0 == cmd_check(UFcT,SHOW_CMD))
			{
				if(rsp_msg_buf.out_fmt==0){
					printf("unsupport command for target!..please see help target. \n");
				}
				if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
					rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
					rsp_msg_buf.error = 242;
					rsp_msg_buf.errtype = 1;
					rsp_msg_buf.cimstat = 7;
					rsp_msg_buf.severity = Low;
				}
				goto job_fail;
			}

	   		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
				if( 0 == strcasecmp(tmp_buf,"/tmp/smash") ){
					memcpy(UFcT,"/",sizeof("/"));
				}

	   			rsp_msg_buf.ufct = (char*)calloc(strlen(UFcT)+1,1);
				if(rsp_msg_buf.ufct == NULL){
					goto free_source;
				}

				memcpy(rsp_msg_buf.ufct,UFcT,strlen(UFcT)+1);
				if(number != NULL){
	   				rsp_msg_buf.inst_num = (char*)calloc(strlen(number)+1,1);
					if(rsp_msg_buf.inst_num == NULL){
						goto free_source;
					}
					memcpy(rsp_msg_buf.inst_num,number,strlen(number)+1);
				}
			}
	    	
			if(rsp_msg_buf.out_fmt==0)
			if(displayall==1 || targets==1)
			{
				printf("\n  Targets :\n");
				total = scandir(tmp_buf,&namelist,selectdir,alphasort);
				if(total > 0)
				{
					for(i=0; i<total; i++)
						printf("	%s\n",namelist[i]->d_name);
				}
				else
					printf("	none\n");
					
				if(namelist) free(namelist);
			}
			
			if(rsp_msg_buf.out_fmt==2)
			if(displayall==1 || targets==1)
			{
				total = scandir(tmp_buf,&namelist,selectdir,alphasort);
				if(total > 0)
				{
					for(i=0; i<total; i++){
						sprintf((rsp_msg_buf.targets+strlen(rsp_msg_buf.targets)),"Targets%d=%s\n",i+1,namelist[i]->d_name);
					}
				}else{
					sprintf(rsp_msg_buf.targets,"%s\n","none");
				}
					
				if(namelist) free(namelist);
			}
			
			i = 0;
			while(St_ResourceTable[i].resourcename)
			{
				if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
					break;
				i++;
			}
	    	
			if(displayall==1 || properties==1)	
			{
				if(rsp_msg_buf.out_fmt==0)
					printf("\n  Properties :\n");
						
				if(NULL != St_ResourceTable[i].classname)
				{										
					rsp_msg_buf.list_property = 1;
					pid_t pid = getpid();
					sprintf(pid_str,"pid=%d",pid);
					rsp_msg_buf.ppid = (int)pid;
					if (fork()==0)
					{
						if(rsp_msg_buf.out_fmt == 1){
							if (-1 == execl("/SMASH/ShowProperty","ShowProperty",St_ResourceTable[i].classname, number,"format=clpxml",pid_str,(char *)0))
							{
								printf("1: EXCE_SHOW\n");
								rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
								printf("1:%s \n",strerror(errno));
								goto free_source;
							}
						}else if(rsp_msg_buf.out_fmt == 2){
							if (-1 == execl("/SMASH/ShowProperty","ShowProperty",St_ResourceTable[i].classname, number,"format=keyword",pid_str,(char *)0))
							{
								printf("2: EXCE_SHOW\n");
								rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
								printf("2:%s \n",strerror(errno));
								goto free_source;
							}
						}else{
							if (-1 == execl("/SMASH/ShowProperty","ShowProperty",St_ResourceTable[i].classname, number,(char *)0))
							{
								printf("1:%s \n",strerror(errno));
								goto free_source;
							}
						}
					}
					wait(NULL);
				}
				else{
					if(rsp_msg_buf.out_fmt==0)
						printf("	None\n");
					if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2))
						rsp_msg_buf.status = CMD_ST_COMPLETED;
				}
			}

			if(rsp_msg_buf.out_fmt==0)
			if(displayall==1 || verbs==1){
				printf("\n  Verbs :\n");
				if(St_ResourceTable[i].cmd & CD_CMD)
					printf("	cd\n");
				if(St_ResourceTable[i].cmd & SHOW_CMD)
					printf("	show\n");
				if(St_ResourceTable[i].cmd & HELP_CMD)
					printf("	help\n");
				if(St_ResourceTable[i].cmd & VERSION_CMD)
					printf("	version\n");
				if(St_ResourceTable[i].cmd & EXIT_CMD)
					printf("	exit\n");
				if(St_ResourceTable[i].cmd & DELETE_CMD)
					printf("	delete\n");
				if(St_ResourceTable[i].cmd & START_CMD)
					printf("	start\n");
				if(St_ResourceTable[i].cmd & STOP_CMD)
					printf("	stop\n");
				if(St_ResourceTable[i].cmd & RESET_CMD)
					printf("	reset\n");
				if(St_ResourceTable[i].cmd & DUMP_CMD)
					printf("	dump\n");
				printf("\n");
			}
			
			if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2))
			if(displayall==1 || verbs==1){
				rsp_msg_buf.support_verbs = St_ResourceTable[i].cmd;
			}

			if(rsp_msg_buf.out_fmt==1){
				rsp_msg_buf.status = CMD_ST_COMPLETED;
				rc = do_show_level_job(cmdline,&rsp_msg_buf);
				if(rc) goto free_source;
			}
			
			if(rsp_msg_buf.out_fmt==2){
				rsp_msg_buf.status = CMD_ST_COMPLETED;
				rc = do_show_level_kd_job(cmdline,&rsp_msg_buf);
				if(rc) goto free_source;
			}
			
			rsp_msg_buf.level_state = 0x1;
		}
		

		rsp_msg_buf.level_state = 0x2;


		if(rsp_msg_buf.out_fmt==1){
			rc = do_show_level_job(cmdline,&rsp_msg_buf);
			if(rc) goto free_source;
			
			#ifdef LEX_DBG_EN
			printf("=======   Dump MSG   =======\n");
			printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
			printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
			#endif
			printf("%s\n",rsp_msg_buf.data);
		}
	
		if(rsp_msg_buf.out_fmt==2){
			rc = do_show_level_kd_job(cmdline,&rsp_msg_buf);
			if(rc) goto free_source;
			
			#ifdef LEX_DBG_EN
			printf("=======   Dump MSG   =======\n");
			printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
			printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
			#endif
			printf("%s\n",rsp_msg_buf.data);
		}
	
	
		fclose(fp);
		fp = NULL;

		#ifdef REMOVE_TEMP_FILE
			sprintf(tmp_buf,"rm -f /tmp/ftree_%d_%d",getpid(),job_id);
			system(tmp_buf);
		#endif
		goto free_source;
	}	

	k = getcwd(NULL,0);
	p = strstr(k,"/tmp/smash");	
	if (NULL == p)
	{
		chdir(path);
		printf("Invalid Targets!.\n");
		chdir(path);
		goto job_fail;
	}
	else
	{
		if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 )
		if(rsp_msg_buf.out_fmt==0){
			p = strstr(k,"/system1");
			if (NULL == p){
				printf("/ \n");
			}
			else{
				printf("%s\n",p);
			}
		}
				
		if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2)){
			p = strstr(k,"/system1");
			if (NULL == p){
				rsp_msg_buf.ufip = (char*)calloc(strlen("/"),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("5:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,"/",strlen("/"));
			}
			else{
				rsp_msg_buf.ufip = (char*)calloc(strlen(p),1);
				if(rsp_msg_buf.ufip == NULL){
					printf("6:Don't have enough memeory!\n");
					goto free_source;
				}
				memcpy(rsp_msg_buf.ufip,p,strlen(p));
			}
		}
	}

	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	for(i=0; isdigit(bname[i])== 0; i++)
	{
		UFcT[i] = bname[i];	
	}
	UFcT[i]='\0';
	number=index(bname,bname[i]);

	if (0 == cmd_check(UFcT,SHOW_CMD))
	{
		if(rsp_msg_buf.out_fmt==0){
			printf("unsupport command for target!..please see help target. \n");
		}
		if( (rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2) ){
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
			rsp_msg_buf.error = 242;
			rsp_msg_buf.errtype = 1;
			rsp_msg_buf.cimstat = 7;
			rsp_msg_buf.severity = Low;
		}
		goto job_fail;
	}
	
	if(rsp_msg_buf.out_fmt==0)
	if(displayall==1 || targets==1)
	{
		printf("\n  Targets :\n");
		total = scandir(getcwd(NULL,0),&namelist,selectdir,alphasort);
		if(total > 0)
		{
			for(i=0; i<total; i++)
				printf("	%s\n",namelist[i]->d_name);
		}
		else
			printf("	none\n");
			
		if(namelist) free(namelist);
	}

	if(rsp_msg_buf.out_fmt==2)
	if(displayall==1 || targets==1)
	{
		total = scandir(getcwd(NULL,0),&namelist,selectdir,alphasort);
		if(total > 0)
		{
			for(i=0; i<total; i++){
				sprintf((rsp_msg_buf.targets+strlen(rsp_msg_buf.targets)),"Targets%d=%s\n",i+1,namelist[i]->d_name);
			}
		}
		else{
			sprintf((rsp_msg_buf.targets),"Targets1=%s\n","none");
		}
			
		if(namelist) free(namelist);
	}	


	i = 0;
	while(St_ResourceTable[i].resourcename)
	{
		if(strcasecmp(St_ResourceTable[i].resourcename, UFcT) == 0)
			break;
		i++;
	}


	if(displayall==1 || properties==1)	
	{
		if(rsp_msg_buf.out_fmt==0)
			printf("\n  Properties :\n");

		if(NULL != St_ResourceTable[i].classname)
		{
			rsp_msg_buf.list_property = 1;
			pid_t pid = getpid();
			sprintf(pid_str,"pid=%d",pid);
			rsp_msg_buf.ppid = (int)pid;
			if (fork()==0)
			{
				if( (rsp_msg_buf.out_fmt == 1) || (rsp_msg_buf.out_fmt == 2) ){

					if (-1 == execl("/SMASH/ShowProperty","ShowProperty",St_ResourceTable[i].classname, number,"format=clpxml",pid_str,(char *)0))
					{
						printf("1: EXCE_SHOW\n");
						rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
						printf("1:%s \n",strerror(errno));
						goto free_source;
					}
				}else{
					if (-1 == execl("/SMASH/ShowProperty","ShowProperty",St_ResourceTable[i].classname, number,(char *)0))
					{
						printf("1:%s \n",strerror(errno));
						goto free_source;
					}
				}
			}
			wait(NULL);
		}
		else{
			if(rsp_msg_buf.out_fmt==0)
				printf("	None\n");
			if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2))
				rsp_msg_buf.status = CMD_ST_COMPLETED;
		}
	}	

	if(rsp_msg_buf.out_fmt==0)
	if(displayall==1 || verbs==1){
		printf("\n  Verbs :\n");
		if(St_ResourceTable[i].cmd & CD_CMD)
			printf("	cd\n");
		if(St_ResourceTable[i].cmd & SHOW_CMD)
			printf("	show\n");
		if(St_ResourceTable[i].cmd & HELP_CMD)
			printf("	help\n");
		if(St_ResourceTable[i].cmd & VERSION_CMD)
			printf("	version\n");
		if(St_ResourceTable[i].cmd & EXIT_CMD)
			printf("	exit\n");
		if(St_ResourceTable[i].cmd & DELETE_CMD)
			printf("	delete\n");
		if(St_ResourceTable[i].cmd & START_CMD)
			printf("	start\n");
		if(St_ResourceTable[i].cmd & STOP_CMD)
			printf("	stop\n");
		if(St_ResourceTable[i].cmd & RESET_CMD)
			printf("	reset\n");
		if(St_ResourceTable[i].cmd & DUMP_CMD)
			printf("	dump\n");
		printf("\n");
	}
	
	if((rsp_msg_buf.out_fmt==1) || (rsp_msg_buf.out_fmt==2))
	if(displayall==1 || verbs==1){
		rsp_msg_buf.support_verbs = St_ResourceTable[i].cmd;
	}
}

job_done:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;

		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}
	
	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_COMPLETED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("valid command format!\n");
}
	rsp_msg_buf_free(&rsp_msg_buf);
	if(fp){
		fclose(fp);
		#ifdef REMOVE_TEMP_FILE
		sprintf(tmp_buf,"rm -f /tmp/ftree_%d_%d",getpid(),job_id);
		system(tmp_buf);
		#endif
	}	
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	if(tmp_buf)	free(tmp_buf);

	return 0;
	
job_fail:
if( (rsp_msg_buf.option & SMASH_OPT_EXAMINE) == 0 ){	
	if(rsp_msg_buf.out_fmt==1){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;

		rc = do_parse_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;

		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);
	}

	if(rsp_msg_buf.out_fmt==2){
		if(rsp_msg_buf.status == CMD_ST_NO_SETTING)
			rsp_msg_buf.status = CMD_ST_EXEC_FAILED;
		rc = clpxml_msg_init(&rsp_msg_buf);
		if(rc) goto free_source;
		
		rc = do_parse_keyword_job(cmdline,&rsp_msg_buf);
		if(rc) goto free_source;
		
		#ifdef LEX_DBG_EN
		printf("=======   Dump MSG   =======\n");
		printf("BUF_SZ: %d\n",rsp_msg_buf.total_sz);
		printf("MSG_SZ: %d\n",rsp_msg_buf.msg_sz);
		#endif
		printf("%s\n",rsp_msg_buf.data);	
	}
}else{
	printf("command format not right!\n");
}

	rsp_msg_buf_free(&rsp_msg_buf);
	if(fp){
		fclose(fp);
		#ifdef REMOVE_TEMP_FILE
		sprintf(tmp_buf,"rm -f /tmp/ftree_%d_%d",getpid(),job_id);
		system(tmp_buf);
		#endif
	}
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	if(tmp_buf)	free(tmp_buf);
	return -1;
	
free_source:
	rsp_msg_buf_free(&rsp_msg_buf);
	if(fp){
		fclose(fp);
		#ifdef REMOVE_TEMP_FILE
		sprintf(tmp_buf,"rm -f /tmp/ftree_%d_%d",getpid(),job_id);
		system(tmp_buf);
		#endif
	}
	if(cmdline)	free(cmdline);
	if(path)	chdir(path);
	if(k) 		free(k);
	if(tmp_buf)	free(tmp_buf);

	return -1;		
}

static void add_simple_arg(const char* arg)
{
	argbuf[argcnt] = (char*)malloc(strlen(arg)+1);
	strcpy(argbuf[argcnt], arg);
	argcnt++;
	argbuf[argcnt] = 0;
}

static void add_arg(const char* xarg)
{
	char* arg;

	char buf[200];
	char xbuf[200];
	int i,j,k;
	int len = strlen(xarg);
	

	k = 0;

	for(i = 0; i < len; i++) {
		if(xarg[i] == '$') {
			if(xarg[i+1] == '$') {
				int pid = getpid();
				sprintf(buf+k, "%d", pid);
				k = strlen(buf);
				i++;
			} else if(xarg[i+1] == 0){
				buf[k] = '$';
				k++;
				break;
			} else {
				for(j = i+1; j < len; j++) {
					if(xarg[j] == '$') 
						break;
					xbuf[j-i-1] = xarg[j];
				}
				xbuf[j-i-1] = 0;
				i = j-1;
				if((arg = getenv(xbuf))) {
					strcpy(buf+k, arg);
					k += strlen(arg);
				}
			}
			
		} else {
			buf[k] = xarg[i];
			k++; 
		}
	}
	buf[k] = 0;
	if(k > 0)
		add_simple_arg(buf);
}

static void do_list_cmd()
{
	int i = 0;
	int j = 0;
	char* p;
	while(argbuf[i]) {
		if(strcasecmp(argbuf[i], ";") == 0) {
			p = argbuf[i];
			argbuf[i] = 0;
			do_pipe_cmd(i-j, argbuf+j);
			argbuf[i] = p;
			j = ++i;
		} else
			i++;
	}
	do_pipe_cmd(i-j, argbuf+j);
}

static int do_pipe_cmd(int argc, char** argv)
{
	int i = 0;
	int j = 0;
	int prepipe = 0;
	int prefd[2];
	int postfd[2];
	char* p;

	while(argv[i]) {
		if(strcasecmp(argv[i], "|") == 0) { 
			p = argv[i];
			argv[i] = 0;

			pipe(postfd); 		
			
			if(prepipe)	
				do_simple_cmd(i-j, argv+j, prefd, postfd);
			else
				do_simple_cmd(i-j, argv+j, 0, postfd);
			argv[i] = p;
			prepipe = 1;
			prefd[0] = postfd[0];
			prefd[1] = postfd[1];
			j = ++i;
		} else
			i++;
	}
	if(prepipe)
		do_simple_cmd(i-j, argv+j, prefd, 0);
	else 
		do_simple_cmd(i-j, argv+j, 0, 0);
	return 0;
}


static int predo_for_redirect(int argc, char** argv, int* re)
{
	int i;
	int redirect = 0;	
	for(i = 1; i < argc; i++) {
		if(strcasecmp(argv[i], "<") == 0) {
			redirect = 1;
			argv[i] = 0;
			break;
		} else if(strcasecmp(argv[i], ">") == 0) {
			redirect = 2;
			argv[i] = 0;
			break;	
		}
	}
	if(redirect) {
		if(argv[i+1]) {
			int fd;
			if(redirect == 2) {
				if((fd = open(argv[i+1], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR)) == -1) {
					fprintf(stderr, "Open out %s failed\n", argv[i+1]);
					return 1;
				}
				dup2(fd, STDOUT_FILENO);
			} else {
				if((fd = open(argv[i+1], O_RDONLY, S_IRUSR|S_IWUSR)) == -1) {
					fprintf(stderr, "Open in %s failed\n", argv[i+1]);
					return 1;
				}
				dup2(fd, STDIN_FILENO);
			}
		} else {
			fprintf(stderr, "Bad redirect, need more arg\n");
			return 1;
		}
	}
	if(re)
		*re = redirect;
	return 0;
}

static int do_simple_cmd(int argc, char** argv, int prefd[], int postfd[])
{
	int pid;
	int status;
	buildin_cmd_handle hd;
	if(argc == 0)
		return 0;

	if(prefd == 0 && postfd == 0) {
		if((hd = get_cmd_handle(argv[0]))) {
			if(predo_for_redirect(argc, argv, 0))
				return 1;
			(*hd)(argc, argv);
			return 0;
		}
	}
	
	if((pid = fork()) == 0) {
		int redirect = 0;
		signal(SIGINT, SIG_DFL);

		if(predo_for_redirect(argc, argv, &redirect))
			exit(1);
		
		if(redirect != 1 && prefd) {
			close(prefd[1]);
			if(prefd[0] != STDIN_FILENO) {
				dup2(prefd[0], STDIN_FILENO);
				close(prefd[0]);
			}
		}
		if(redirect != 2 && postfd) {
			close(postfd[0]);
			if(postfd[1] != STDOUT_FILENO) {
				dup2(postfd[1], STDOUT_FILENO);
				close(postfd[1]);
			}
		}
		if((hd = get_cmd_handle(argv[0]))) {
			(*hd)(argc, argv);
			exit(0);
		}

			fprintf(stderr, "%s command not support now.\n", argv[0]);
			exit(0);
	}
	waitpid(pid, &status, 0);
	if(postfd) { 
		close(postfd[1]); 
	}
	return 0;
}


static void reset_args()
{
	int i;
	for(i = 0; i < argcnt; i++) {
		free(argbuf[i]);
		argbuf[i] = 0;
	}
	argcnt = 0;
}

static int my_yyinput(char* buf, int max)
{
	int n;
	n = (max < (mylim-myptr)) ? max : (mylim-myptr);

	if(n > 0) {
		memcpy(buf, myptr, n);
		myptr += n;
	}
	return n;
}


int chk_valid_opt(int argc, char** argv, char *cmd_name, int tbl_idx, RSP_MSG_BUF_TAG *rsp_msg_buf, int cmd_flag)
{
	int i=0;
	int idx=0;
	char *path=NULL, *p = NULL, *k=NULL, *number=NULL;
	char bname[255];
	char UFcT[255];
	char target[255];

	
	for(i=1 ; i<argc ; i++){
		if(NULL != argv[i]){
			if(strchr(argv[i],'-')){
				if(0 == strcasecmp(argv[i],"-w") || 0 == strcasecmp(argv[i],"-wait")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_WAIT) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("wait option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else if(0 == strcasecmp(argv[i],"-v") || 0 == strcasecmp(argv[i],"-version")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_VERSION) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("version option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else if(0 == strcasecmp(argv[i],"-source")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_SOURCE) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("source option not support in %s command !\n",cmd_name);
						return -1;
					}
					
					if(NULL != argv[++i]){
							continue;
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("source option need an argument!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-o") || 0 == strcasecmp(argv[i],"-output")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_OUTPUT) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("output option not support in %s command !\n",cmd_name);
						return -1;
					}
					if(NULL != argv[++i]){
						if(0 != strcasecmp(argv[i],"format=")){
							if(rsp_msg_buf->out_fmt==0) printf("output format not support!\n");
							return -1;
						}
						else{
							continue;
						}
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("output format not support!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-l") || 0 == strcasecmp(argv[i],"-level")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_LEVEL) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("level option not support in %s command !\n",cmd_name);
						return -1;
					}
					
					if(NULL != argv[++i]){
							continue;
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("level option need an argument!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-k") || 0 == strcasecmp(argv[i],"-keep")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_KEEP) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("keep option not support in %s command !\n",cmd_name);
						return -1;
					}
					
					if(NULL != argv[++i]){
							continue;
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("keep option need an argument!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-h") || 0 == strcasecmp(argv[i],"-help")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_HELP) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("help option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else if(0 == strcasecmp(argv[i],"-f") || 0 == strcasecmp(argv[i],"-force")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_FORCE) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("force option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else if(0 == strcasecmp(argv[i],"-x") || 0 == strcasecmp(argv[i],"-examine")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_EXAMINE) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("examine option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else if(0 == strcasecmp(argv[i],"-d") || 0 == strcasecmp(argv[i],"-display")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_DISPLAY) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("display option not support in %s command !\n",cmd_name);
						return -1;
					}
					
					if(NULL != argv[++i]){
							continue;
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("display option need arguments!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-destination")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_DESTINATION) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("destination option not support in %s command !\n",cmd_name);
						return -1;
					}
					if(NULL != argv[++i]){
							continue;
					}else{
						if(rsp_msg_buf->out_fmt==0) printf("destination option need an arguments!\n");
						return -1;
					}
				}
				else if(0 == strcasecmp(argv[i],"-a") || 0 == strcasecmp(argv[i],"-all")){
					if( (verb_option_tbl[tbl_idx].support_opt & SMASH_OPT_ALL) == 0){
						if(rsp_msg_buf->out_fmt==0) printf("all option not support in %s command !\n",cmd_name);
						return -1;
					}
					continue;
				}
				else{
					printf("Wrong option in %s command !\n",cmd_name);
					return -1;
				}
			}else{
				if(0 == strcasecmp(argv[i],"==") || strchr(argv[i],'=')){
					continue;
				}

				if(NULL != argv[i])
				{
					path = getcwd(NULL,0);
					argv[i] = strlwr(argv[i]);
					if('/' == argv[i][0])
						sprintf(target,"/tmp/smash%s",argv[i]);
					else
						sprintf(target,"%s",argv[i]);
					
					if( -1 == chdir(target))
					{
						if(rsp_msg_buf->out_fmt==0) printf("Invalid Targets!.\n");
						return -1;
					}else{
							k = getcwd(NULL,0);
							p = strstr(k,"/tmp/smash");
														
							if (NULL == p)
							{
								chdir(path);
								if(rsp_msg_buf->out_fmt==0) printf("Invalid Targets!.\n");
								return -1;
							}
							else
							{
								if( (rsp_msg_buf->option & SMASH_OPT_EXAMINE) == 0 )
								if(rsp_msg_buf->out_fmt==0){
									p = strstr(k,"/system1");
									if (NULL == p){
									printf("/ \n");
									}else{
									printf("%s\n",p);
									}
								}
								
								
								if((rsp_msg_buf->out_fmt==1) || (rsp_msg_buf->out_fmt==2)){
									p = strstr(k,"/system1");
									if (NULL == p){
										rsp_msg_buf->ufip = (char*)calloc(strlen("/"),1);
										if(rsp_msg_buf->ufip == NULL){
											printf("5:Don't have enough memeory!\n");
											return -1;
										}
										memcpy(rsp_msg_buf->ufip,"/",strlen("/"));
									}
									else{
										rsp_msg_buf->ufip = (char*)calloc(strlen(p),1);
										if(rsp_msg_buf->ufip == NULL){
											printf("6:Don't have enough memeory!\n");
											return -1;
										}
										memcpy(rsp_msg_buf->ufip,p,strlen(p));
									}
								}								

							}
						
							sprintf(bname,"%s",basename(getcwd(NULL,0)));
							for(idx=0; isdigit(bname[idx])== 0; idx++)
							{
								UFcT[idx] = bname[idx];
							}
							UFcT[idx]='\0';
							number=index(bname,bname[idx]);
							
							if(cmd_flag != -1)
							{
								if (0 == cmd_check(UFcT,cmd_flag))
								{
									if(rsp_msg_buf->out_fmt==0){
										printf("unsupport command for target!..please see help target. \n");
										goto job_fail;
									}
								}
							}else{
								if(rsp_msg_buf->out_fmt==0){
									printf("unsupport command! \n");
									goto job_fail;
								}
							}
																
							chdir(path);
							if(k) free(k);
					}
				}
			}
		}				
	}

	return 0;
job_fail:
	if(k) free(k);
	if(path) free(path);
	return -1;
}

int clpxml_msg_init(RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	int i=0;
	char *UFcT  = NULL;
	char *bname = NULL;
	char *number= NULL;
	
	bname = (char*)calloc(FULL_PATH_NAME_MAX_LEN,1);
	if(bname == NULL) return -1;
	
	UFcT = (char*)calloc(UFCT_MAX_LEN,1);
	if(UFcT == NULL){
		goto clpxml_msg_init_fail;
	}



	sprintf(bname,"%s",basename(getcwd(NULL,0)));
	
	if(strcasecmp(bname,"smash")){

		for(i=0; isdigit(bname[i])== 0; i++){
			UFcT[i] = bname[i];
		}
		UFcT[i]='\0';

		number=index(bname,bname[i]);
		if(number == 0){
			goto clpxml_msg_init_fail;
		}

		rsp_msg_buf->inst_num = (char*)calloc(strlen(number)+1,1);
		if(rsp_msg_buf->inst_num == NULL){
			goto clpxml_msg_init_fail;
		}
		memcpy(rsp_msg_buf->inst_num,number,strlen(number)+1);				
	}else{
		memcpy(UFcT,"/",sizeof("/"));
	}

	
	rsp_msg_buf->ufct = (char*)calloc(strlen(UFcT)+1,1);	
	if(rsp_msg_buf->ufct == NULL){
		goto clpxml_msg_init_fail;
	}
	memcpy(rsp_msg_buf->ufct,UFcT,strlen(UFcT)+1);

	
	if(bname)	free(bname);
	if(UFcT)	free(UFcT);
	return 0;
	
clpxml_msg_init_fail:
	if(bname)	free(bname);
	if(UFcT)	free(UFcT);
	
	return -1;
}

int rsp_msg_buf_init(RSP_MSG_BUF_TAG *rsp_msg_buf)
{	
	rsp_msg_buf->src_addr = NULL;
	rsp_msg_buf->dst_addr = NULL;
	rsp_msg_buf->targets = NULL;
	rsp_msg_buf->message = NULL;
	rsp_msg_buf->owningentity = NULL;
	rsp_msg_buf->recmdaction = NULL;
	rsp_msg_buf->cmd_help_msg = NULL;
	rsp_msg_buf->cmd = NULL;
	rsp_msg_buf->inst_num = NULL;
	rsp_msg_buf->ufct = NULL;
	rsp_msg_buf->ufip = NULL;
	rsp_msg_buf->data = NULL;	
	rsp_msg_buf->data = (char *)calloc(SM_DEF_MSG_SZ,1);
	if(rsp_msg_buf->data == NULL){
		printf("Allocate Mem Failed\n");
		return -1;
	}

	rsp_msg_buf->total_sz = SM_DEF_MSG_SZ;
	rsp_msg_buf->msg_sz = 0;
	rsp_msg_buf->ppid = 0;
	rsp_msg_buf->out_fmt = 0;
	rsp_msg_buf->option = 0;
	rsp_msg_buf->status = CMD_ST_NO_SETTING;
	
	
	rsp_msg_buf->error	 = 0;
	rsp_msg_buf->errtype = -1;
	rsp_msg_buf->cimstat = -1;
	rsp_msg_buf->severity= EL_SERVERITY_NO_SETTING;
	rsp_msg_buf->support_verbs = -1;
	rsp_msg_buf->list_property = 0xff;
	rsp_msg_buf->level_state = 0x0;
	rsp_msg_buf->probcause_num = -1;
	rsp_msg_buf->message_id = -1;
	rsp_msg_buf->message_arg = -1;


	return 0;
}

void rsp_msg_buf_free(RSP_MSG_BUF_TAG *rsp_msg_buf)
{
	if(rsp_msg_buf->dst_addr)			free(rsp_msg_buf->dst_addr);
	if(rsp_msg_buf->src_addr)			free(rsp_msg_buf->src_addr);
	if(rsp_msg_buf->cmd_help_msg)		free(rsp_msg_buf->cmd_help_msg);
	if(rsp_msg_buf->cmd)				free(rsp_msg_buf->cmd);
	if(rsp_msg_buf->inst_num) 			free(rsp_msg_buf->inst_num);
	if(rsp_msg_buf->ufct) 				free(rsp_msg_buf->ufct);
	if(rsp_msg_buf->ufip)				free(rsp_msg_buf->ufip);
	if(rsp_msg_buf->data) 				free(rsp_msg_buf->data);
	if(rsp_msg_buf->recmdaction) 		free(rsp_msg_buf->recmdaction);
	if(rsp_msg_buf->targets)			free(rsp_msg_buf->targets);
}
