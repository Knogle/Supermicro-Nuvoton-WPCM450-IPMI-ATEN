
#ifndef _IXML_H_
#define _IXML_H_

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>

typedef int BOOL;

#define DOMString   char *


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef INOUT
#define INOUT
#endif





typedef enum
{
    eINVALID_NODE                   = 0,
    eELEMENT_NODE                   = 1,
    eATTRIBUTE_NODE                 = 2,
    eTEXT_NODE                      = 3,
    eCDATA_SECTION_NODE             = 4,
    eENTITY_REFERENCE_NODE          = 5,
    eENTITY_NODE                    = 6,                
    ePROCESSING_INSTRUCTION_NODE    = 7,
    eCOMMENT_NODE                   = 8,
    eDOCUMENT_NODE                  = 9,
    eDOCUMENT_TYPE_NODE             = 10,
    eDOCUMENT_FRAGMENT_NODE         = 11,
    eNOTATION_NODE                  = 12,

}   IXML_NODE_TYPE;


typedef enum 
{   
    IXML_INDEX_SIZE_ERR                 = 1,
    IXML_DOMSTRING_SIZE_ERR             = 2,
    IXML_HIERARCHY_REQUEST_ERR          = 3,
    IXML_WRONG_DOCUMENT_ERR             = 4,
    IXML_INVALID_CHARACTER_ERR          = 5,
    IXML_NO_DATA_ALLOWED_ERR            = 6,
    IXML_NO_MODIFICATION_ALLOWED_ERR    = 7,
    IXML_NOT_FOUND_ERR                  = 8,
    IXML_NOT_SUPPORTED_ERR              = 9,
    IXML_INUSE_ATTRIBUTE_ERR            = 10,
    IXML_INVALID_STATE_ERR              = 11,
    IXML_SYNTAX_ERR                     = 12,
    IXML_INVALID_MODIFICATION_ERR       = 13,
    IXML_NAMESPACE_ERR                  = 14,
    IXML_INVALID_ACCESS_ERR             = 15,

    IXML_SUCCESS                        = 0,
    IXML_NO_SUCH_FILE                   = 101,
    IXML_INSUFFICIENT_MEMORY            = 102,
    IXML_FILE_DONE                      = 104,
    IXML_INVALID_PARAMETER              = 105,
    IXML_FAILED                         = 106,
    IXML_INVALID_ITEM_NUMBER            = 107,

} IXML_ERRORCODE;


#define DOCUMENTNODENAME    "#document"
#define TEXTNODENAME        "#text"
#define CDATANODENAME       "#cdata-section"


typedef struct _IXML_Document *Docptr;

typedef struct _IXML_Node    *Nodeptr;
typedef struct _IXML_Node
{
    DOMString       nodeName;
    DOMString       nodeValue;
    IXML_NODE_TYPE  nodeType;
    DOMString       namespaceURI;
    DOMString       prefix;
    DOMString       localName;
    BOOL            readOnly;

    Nodeptr         parentNode;
    Nodeptr         firstChild;
    Nodeptr         prevSibling;
    Nodeptr         nextSibling;
    Nodeptr         firstAttr;
    Docptr          ownerDocument;

} IXML_Node;

typedef struct _IXML_Document
{
    IXML_Node    n;
} IXML_Document;

typedef struct _IXML_CDATASection
{
    IXML_Node    n;
} IXML_CDATASection;

typedef struct _IXML_Element
{
    IXML_Node   n;
    DOMString   tagName;

} IXML_Element;

typedef struct _IXML_ATTR
{
    IXML_Node   n;
    BOOL        specified;
    IXML_Element *ownerElement;
} IXML_Attr;

typedef struct _IXML_Text
{
    IXML_Node   n;
} IXML_Text;

typedef struct _IXML_NodeList
{
    IXML_Node    *nodeItem;
    struct  _IXML_NodeList *next;
} IXML_NodeList;


typedef struct _IXML_NamedNodeMap
{
    IXML_Node                 *nodeItem;
    struct _IXML_NamedNodeMap *next;
} IXML_NamedNodeMap;

#ifdef __cplusplus
extern "C" {
#endif








const DOMString
ixmlNode_getNodeName(IXML_Node *nodeptr 
                    );



DOMString               
ixmlNode_getNodeValue(IXML_Node *nodeptr  
                     );



int                     
ixmlNode_setNodeValue(IXML_Node *nodeptr, 
                      char *newNodeValue  
                  );



unsigned short    
ixmlNode_getNodeType(IXML_Node *nodeptr  
                    );



IXML_Node*                   
ixmlNode_getParentNode(IXML_Node *nodeptr  

                      );



IXML_NodeList*               
ixmlNode_getChildNodes(IXML_Node *nodeptr  

                   );



IXML_Node*                   
ixmlNode_getFirstChild(IXML_Node *nodeptr  

);



IXML_Node*                   
ixmlNode_getLastChild(IXML_Node *nodeptr  

                  );



IXML_Node*                   
ixmlNode_getPreviousSibling(IXML_Node *nodeptr  

                        );



IXML_Node*                   
ixmlNode_getNextSibling(IXML_Node *nodeptr  

                    );



IXML_NamedNodeMap*           
ixmlNode_getAttributes(IXML_Node *nodeptr  

                   );



IXML_Document*               
ixmlNode_getOwnerDocument(IXML_Node *nodeptr  

                      );



const DOMString         
ixmlNode_getNamespaceURI(IXML_Node *nodeptr  

                     );



DOMString               
ixmlNode_getPrefix(IXML_Node *nodeptr  
               );



const DOMString         
ixmlNode_getLocalName(IXML_Node *nodeptr  

                  );



int     
ixmlNode_insertBefore(IXML_Node *nodeptr,   

                      IXML_Node* newChild,      
                      IXML_Node* refChild       

                  );



int     
ixmlNode_replaceChild(IXML_Node *nodeptr,     

                      IXML_Node* newChild,        
                      IXML_Node* oldChild,        
                      IXML_Node** returnNode      

                  );



int     
ixmlNode_removeChild(IXML_Node *nodeptr,     
                     IXML_Node* oldChild,  
                     IXML_Node **returnNode

                 );



int     
ixmlNode_appendChild(IXML_Node *nodeptr,  
                     IXML_Node* newChild      
                 );



BOOL    
ixmlNode_hasChildNodes(IXML_Node *nodeptr  
                   );



IXML_Node*   
ixmlNode_cloneNode(IXML_Node *nodeptr,  
                   BOOL deep

                  );



BOOL    
ixmlNode_hasAttributes(IXML_Node *node  
                      );



void    
ixmlNode_free(IXML_Node *IXML_Node  
             );









void    
ixmlAttr_free(IXML_Attr *attrNode  
             );










void    
ixmlCDATASection_init(IXML_CDATASection *nodeptr  
                     );




void    
ixmlCDATASection_free(IXML_CDATASection *nodeptr  
                     );








void    
ixmlDocument_init(IXML_Document *nodeptr  
                 );



int ixmlDocument_createDocumentEx(IXML_Document** doc 

		                  );




IXML_Document* ixmlDocument_createDocument();



int
ixmlDocument_createElementEx(IXML_Document *doc,  
                             const DOMString tagName,  

                             IXML_Element **rtElement

                            );



IXML_Element*
ixmlDocument_createElement(IXML_Document *doc,  
                           const DOMString tagName    
                           );




int
ixmlDocument_createTextNodeEx(IXML_Document *doc,  
                              const DOMString data,      

                              IXML_Node** textNode 

                              );




IXML_Node*
ixmlDocument_createTextNode(IXML_Document *doc,  
                            const DOMString data       

                            );



int
ixmlDocument_createCDATASectionEx(IXML_Document *doc,  

                                  DOMString data,      

                                  IXML_CDATASection** cdNode   

                                 );




IXML_CDATASection*
ixmlDocument_createCDATASection(IXML_Document *doc,  

                                DOMString data  

                               );



IXML_Attr*
ixmlDocument_createAttribute(IXML_Document *doc,  
                             char *name      
                            );




int
ixmlDocument_createAttributeEx(IXML_Document *doc,  

                               char *name,      
                               IXML_Attr** attrNode

                              );




IXML_NodeList*
ixmlDocument_getElementsByTagName(IXML_Document *doc,     
                                  DOMString tagName  
                                 );




int
ixmlDocument_createElementNSEx(IXML_Document *doc,           

                               DOMString namespaceURI,  

                               DOMString qualifiedName,  

                               IXML_Element** rtElement

                              );




IXML_Element*
ixmlDocument_createElementNS(IXML_Document *doc,           
                             DOMString namespaceURI,  

                             DOMString qualifiedName  

                             );



int
ixmlDocument_createAttributeNSEx(IXML_Document *doc,

                                 DOMString namespaceURI, 
                                 DOMString qualifiedName, 
                                 IXML_Attr** attrNode

                                );   



IXML_Attr*
ixmlDocument_createAttributeNS(IXML_Document *doc, 

                               DOMString namespaceURI, 
                               DOMString qualifiedName 
                              );   



IXML_NodeList*   
ixmlDocument_getElementsByTagNameNS(IXML_Document* doc,          
                                    DOMString namespaceURI, 

                                    DOMString localName     

                                    );



IXML_Element*    
ixmlDocument_getElementById(IXML_Document* doc,         

                            DOMString tagName  
                            );



void        
ixmlDocument_free(IXML_Document* doc  
                 );



int         
ixmlDocument_importNode(IXML_Document* doc,     
                        IXML_Node* importNode,  
                        BOOL deep,         

                        IXML_Node** rtNode      

                       );







void ixmlElement_init(IXML_Element *element  
                     );




const DOMString
ixmlElement_getTagName(IXML_Element* element  

                      );



DOMString   
ixmlElement_getAttribute(IXML_Element* element,  

                         DOMString name     
                        );



int         
ixmlElement_setAttribute(IXML_Element* element,  

                         DOMString name,    
                         DOMString value    

                        );



int         
ixmlElement_removeAttribute(IXML_Element* element,  

                            DOMString name     
                           );              



IXML_Attr*       
ixmlElement_getAttributeNode(IXML_Element* element,  

                             DOMString name     
                            );



int         
ixmlElement_setAttributeNode(IXML_Element* element,  

                             IXML_Attr* newAttr,     
                             IXML_Attr** rtAttr      

                            );



int         
ixmlElement_removeAttributeNode(IXML_Element* element,  

                                IXML_Attr* oldAttr,     

                                IXML_Attr** rtAttr      

                               );



IXML_NodeList*   
ixmlElement_getElementsByTagName(IXML_Element* element,  

                                 DOMString tagName  

                                );




DOMString   
ixmlElement_getAttributeNS(IXML_Element* element,       

                           DOMString namespaceURI, 
                           DOMString localname     
                          );



int         
ixmlElement_setAttributeNS(IXML_Element* element,         

                           DOMString namespaceURI,   
                           DOMString qualifiedName,  
                           DOMString value 
                          );



int         
ixmlElement_removeAttributeNS(IXML_Element* element,        

                              DOMString namespaceURI,  
                              DOMString localName      
                             );



IXML_Attr*       
ixmlElement_getAttributeNodeNS(IXML_Element* element,        

                               DOMString namespaceURI,  
                               DOMString localName      
                              );



int         
ixmlElement_setAttributeNodeNS(IXML_Element* element,  

                               IXML_Attr*   newAttr,     
                               IXML_Attr**  rcAttr      

                              );



IXML_NodeList*   
ixmlElement_getElementsByTagNameNS(IXML_Element* element,        

                                   DOMString namespaceURI,  

                                   DOMString localName      

                                  );



BOOL        
ixmlElement_hasAttribute(IXML_Element* element, 

                         DOMString name    
                        );



BOOL        
ixmlElement_hasAttributeNS(IXML_Element* element,       

                           DOMString namespaceURI, 
                           DOMString localName     
                          );



void        
ixmlElement_free(IXML_Element* element  
                );








unsigned long 
ixmlNamedNodeMap_getLength(IXML_NamedNodeMap *nnMap  

                          );



IXML_Node*   
ixmlNamedNodeMap_getNamedItem(IXML_NamedNodeMap *nnMap, 
                              DOMString name       
                             );



IXML_Node*   
ixmlNamedNodeMap_setNamedItem(IXML_NamedNodeMap *nnMap, 

                              IXML_Node *arg            

                             );



IXML_Node*   
ixmlNamedNodeMap_removeNamedItem(IXML_NamedNodeMap *nnMap,  

                                 DOMString name        
                                );



IXML_Node*   
ixmlNamedNodeMap_item(IXML_NamedNodeMap *nnMap, 

                      unsigned long index  
                     );




IXML_Node*   
ixmlNamedNodeMap_getNamedItemNS(IXML_NamedNodeMap *nnMap,    

                                DOMString *namespaceURI,

                                DOMString localName     

                               );



IXML_Node*   
ixmlNamedNodeMap_setNamedItemNS(IXML_NamedNodeMap *nnMap, 

                                IXML_Node *arg 
                               );



IXML_Node*   
ixmlNamedNodeMap_removeNamedItemNS(IXML_NamedNodeMap *nnMap,    

                                   DOMString namespaceURI, 

                                   DOMString localName     

                                  );



void    
ixmlNamedNodeMap_free(IXML_NamedNodeMap *nnMap  
                     );








IXML_Node*           
ixmlNodeList_item(IXML_NodeList *nList,     

                  unsigned long index  
                 );



unsigned long   
ixmlNodeList_length(IXML_NodeList *nList  

                   );



void            
ixmlNodeList_free(IXML_NodeList *nList  
                 );






#define     ixmlPrintDocument(doc)  ixmlPrintNode((IXML_Node *)doc)

#define ixmlDocumenttoString(doc)	ixmlNodetoString((IXML_Node *)doc)



DOMString   
ixmlPrintNode(IXML_Node *doc  
             );



DOMString   
ixmlNodetoString(IXML_Node *doc  
                );



void
ixmlRelaxParser(char errorChar);



IXML_Document*
ixmlParseBuffer(char *buffer 

               );




int
ixmlParseBufferEx(char *buffer, 

                  IXML_Document** doc 

                );



IXML_Document*
ixmlLoadDocument(char* xmlFile      

                );



int 
ixmlLoadDocumentEx(char* xmlFile,      

                   IXML_Document** doc   

                 );



DOMString   
ixmlCloneDOMString(const DOMString src  
                  );



void        
ixmlFreeDOMString(DOMString buf  
                 );

#ifdef __cplusplus
}
#endif


#endif  
