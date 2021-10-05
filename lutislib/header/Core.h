#ifndef HEADER_CORE_H
#define HEADER_CORE_H

#include "Type.h"
#include <vector>
#include <string>
#include <jni.h>
#include <Magick++.h>

namespace lutis 
{
    namespace core 
    {

#define CLEAN_UP(out) { \
                            lutis::type::Byte* imBytes = out; \
                            delete[] imBytes; \
                            }

        static int DecodeFromBufferToMagickImage(JNIEnv *env, const jbyteArray& data, Magick::Image& dest)
        {

            lutis::type::Byte is_copy;
            jbyte* array_element = env->GetByteArrayElements(data, &is_copy);
            jsize length_data = env->GetArrayLength(data);

            printf("is copy %d\n", is_copy);

            lutis::type::Byte* data_source = (lutis::type::Byte*) array_element;

            // decode from buffer to Magick Image
            Magick::Blob blobIn(data_source, length_data);
            try 
            {
                dest.read(blobIn);
            } catch(Magick::Error& err)
            {
                return -1;
            }

            return 0;
        }
    }
}

#endif