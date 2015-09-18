#ifndef KERNEL_LIST_H
#define KERNEL_LIST_H

struct SLKREG_node
{
    /* Pointer to object */
    void *pObj;

    /* Object size, for copying purposes */
    int size;

    /* Whether or not the registry can deallocate the object */
    int isOwner;

    /* Previous and next nodes in list */
    struct SLKREG_node *pNext;
    struct SLKREG_node *pPrev;
};

/* Schema interface for managing specific registry items */
struct SLKREG_schema
{
    /* Callback function for comparing two registry objects for sorting
     * pNew: Newer object for comparison
     * pOld: Existing object for comparison
     * Return -1 if pNew < pOld, 0 if pNew == pOld, 1 if pNex > pOld
     */
    int (*node_cmp)(void *pNew, void *pOld);

    /* Adds new node
     * pObj: Pointer to node object
     * size: Size of allocated object
     * isOwner: Nonzero if this registry has deallocating rights over this object
     */
    void * (*node_add)(void *pObj, int size, int isOwner);

    /* Callback for deallocating a registry object. Is only called when
     * the registry owns this object.
     * pObj: Pointer to node object
     * isOwner: Whether or not registry is owner of this object
     */
    void (*node_free)(void *pObj);
};

/* Represents a registry of linked-list structs */
struct SLKREG
{
    /* Interface schema for this registry list */
    struct SLKREG_schema schema;
     
    /* Root node of registry */
    struct SLKREG_node root;
};

/* Creates new registry */
struct SLKREG SLFREG_new();

/* Frees registry */
void SLFREG_free();

#endif
