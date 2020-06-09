#ifndef _WSMAN_ACCOUNT_HANDLER_H_
#define _WSMAN_ACCOUNT_HANDLER_H_

#ifdef _WSMAN_ACCOUNT_HANDLER_C_

#else
extern int wsman_account_del(char *username);
extern int wsman_account_add(char *username, char *passwd);
#endif

#endif
