/**
 * Code for loading and registering plugins with the kernel
 */
#ifndef BASEPLUGINLOADER_H
#define BASEPLUGINLOADER_H

/* Kernel Plugin Entry */
struct SLKPLG
{
    /* Plugin name */
    char *name;
}

/* Loads a raw dll as a bare-bones plugin from disk */
struct SLKPLG *SLK_loadDLib();

#endif
