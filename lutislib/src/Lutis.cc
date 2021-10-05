#include <stdio.h>
#include <vector>
#include <cmath>
#include <Magick++.h>
#include "../header/Core.h"
#include "../header/Type.h"
#include "../header/com_wuriyanto_lab_lutisjvm_Lutis.h"

//namespace lutis
//{
//
//    JNIEXPORT jint JNICALL Java_com_wuriyanto_lab_lutisjvm_Lutis_powerN
//        (JNIEnv *, jobject, jint a, jint b)
//    {
//        int _a = a;
//        int _b = b;
//
//        return (jint) std::pow(_a, _b);
//    }
//}

JNIEXPORT jint JNICALL Java_com_wuriyanto_lab_lutisjvm_Lutis_powerN
        (JNIEnv *, jobject, jint a, jint b)
{
    int _a = a;
    int _b = b;

    return (jint) std::pow(_a, _b);
}