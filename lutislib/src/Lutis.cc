#include <stdio.h>
#include <vector>
#include <Magick++.h>
#include "../header/Core.h"
#include "../header/Type.h"
#include "../header/com_wuriyanto_lab_lutisjvm_Lutis.h"

jint throwError(JNIEnv *env, char *message)
{
    jclass exClass;
    char className[] = "java/lang/Exception";

    exClass = (*env).FindClass(className);
    if (exClass == NULL) {
        return throwError(env, className);
    }

    return (*env).ThrowNew(exClass, message);
}

JNIEXPORT jbyteArray JNICALL Java_com_wuriyanto_lab_lutisjvm_Lutis_rotateImageN
  (JNIEnv *env , jobject obj, jdouble angle, jbyteArray data)
{
    double _angle = angle;

    if (_angle <= 0)
    {
        throwError(env, "angle should greater than 0");
    }

    Magick::Image image;

    int decodeRes = lutis::core::DecodeFromBufferToMagickImage(env, data, image);
    if (decodeRes != 0)
    {
        throwError(env, "error decoding image data");
    }

    // operations
    try 
    {
        image.rotate(angle);
    } catch(Magick::Error& err)
    {
       throwError(env, "error rotating image");
    }

    // encode
    Magick::Blob blobOut;
    image.magick("PNG");
    image.write(&blobOut);

    lutis::type::Byte datas[blobOut.length()];
    memcpy(datas, blobOut.data(), blobOut.length());

    jbyte* result_e = new jbyte[blobOut.length()];
    jbyteArray result = env->NewByteArray(blobOut.length());
    for (int i = 0; i < blobOut.length(); i++)
    {
        result_e[i] = (jbyte) datas[i];
    }
    env->SetByteArrayRegion(result, 0, blobOut.length(), result_e);
    return result;
}