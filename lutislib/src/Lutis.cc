#include <stdio.h>
#include <vector>
#include <string>
#include <Magick++.h>
#include "../header/Core.h"
#include "../header/Type.h"
#include "../header/com_wuriyanto_lab_lutisjvm_Lutis.h"

jint throwError(JNIEnv *env, const std::string message)
{
    jclass exClass;
    std::string className = "java/lang/Exception";

    exClass = (*env).FindClass(className.c_str());
    if (exClass == NULL) {
        return throwError(env, className);
    }

    return (*env).ThrowNew(exClass, message.c_str());
}

JNIEXPORT jbyteArray JNICALL Java_com_wuriyanto_lab_lutisjvm_Lutis_rotateImageN
  (JNIEnv *env , jobject obj, jdouble angle, jbyteArray data)
{
    double _angle = angle;

    if (_angle <= 0)
    {
        std::string msg = "angle should greater than 0";
        throwError(env, msg);
    }

    Magick::Image image;

    int decodeRes = lutis::core::DecodeFromBufferToMagickImage(env, data, image);
    if (decodeRes != 0)
    {
        std::string msg = "error decoding image data";
        throwError(env, msg);
    }

    // operations
    try 
    {
        image.rotate(angle);
    } catch(Magick::Error& err)
    {
        std::string msg = "error rotating image";
       throwError(env, msg);
    }

    // encode
    Magick::Blob blobOut;
    image.magick("PNG");
    image.write(&blobOut);

    lutis::type::Byte datas[blobOut.length()];
    MEMCPY(datas, blobOut.data(), blobOut.length());

    jbyte* result_e = new jbyte[blobOut.length()];
    jbyteArray result = env->NewByteArray(blobOut.length());
    for (int i = 0; i < blobOut.length(); i++)
    {
        result_e[i] = (jbyte) datas[i];
    }
    env->SetByteArrayRegion(result, 0, blobOut.length(), result_e);

    CLEAN_UP((lutis::type::Byte*)result_e);
    return result;
}