/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
/*
 * This file contains the automatically generated loader-side
 * functions that form part of the extension.
 *
 * This file is awlays compiled into all loaders but compiles
 * to nothing if this extension is not enabled in the loader
 * at build time.
 */
#include "imageResize_autodefs.h"
#include "s3eEdk.h"
#include "imageResize.h"
//Declarations of Init and Term functions
extern s3eResult imageResizeInit();
extern void imageResizeTerminate();


s3eResult imageResizeRegister(imageResizeCallback cbid, s3eCallback fn, void* pData)
{
    return s3eEdkCallbacksRegister(S3E_EXT_IMAGERESIZE_HASH, IMAGERESIZE_CALLBACK_MAX, cbid, fn, pData, 0);
};

s3eResult imageResizeUnRegister(imageResizeCallback cbid, s3eCallback fn)
{
    return s3eEdkCallbacksUnRegister(S3E_EXT_IMAGERESIZE_HASH, IMAGERESIZE_CALLBACK_MAX, cbid, fn);
}

void imageResizeRegisterExt()
{
    /* fill in the function pointer struct for this extension */
    void* funcPtrs[4];
    funcPtrs[0] = (void*)imageResizeRegister;
    funcPtrs[1] = (void*)imageResizeUnRegister;
    funcPtrs[2] = (void*)resizeImage;
    funcPtrs[3] = (void*)cnsSaveImageBufferToGallery;

    /*
     * Flags that specify the extension's use of locking and stackswitching
     */
    int flags[4] = { 0 };

    /*
     * Register the extension
     */
    s3eEdkRegister("imageResize", funcPtrs, sizeof(funcPtrs), flags, imageResizeInit, imageResizeTerminate, 0);
}

#if !defined S3E_BUILD_S3ELOADER

#if defined S3E_EDK_USE_STATIC_INIT_ARRAY
int imageResizeStaticInit()
{
    void** p = g_StaticInitArray;
    void* end = p + g_StaticArrayLen;
    while (*p) p++;
    if (p < end)
        *p = (void*)&imageResizeRegisterExt;
    return 0;
}

int g_imageResizeVal = imageResizeStaticInit();

#elif defined S3E_EDK_USE_DLLS
S3E_EXTERN_C S3E_DLL_EXPORT void RegisterExt()
{
    imageResizeRegisterExt();
}
#endif

#endif
