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

        static int DecodeFromBufferToMagickImage(const jbyteArray& data, Magick::Image& dest)
        {
            // const lutis::type::Byte* arrs = reinterpret_cast<lutis::type::Byte*>(data.Data());

            // size_t length = data.Length();

            // lutis::type::Byte* datas = new lutis::type::Byte[length];
            // memcpy(datas, arrs, length);

            // // decode from buffer to Magick Image
            // Magick::Blob blobIn(datas, length);
            // try 
            // {
            //     dest.read(blobIn);
            // } catch(Magick::Error& err)
            // {
            //     CLEAN_UP(datas);
            //     return -1;
            // }

            // CLEAN_UP(datas);
            return 0;
        }
    }
}

#endif