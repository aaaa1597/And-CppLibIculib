#include <jni.h>
#include <string>
#include <android/log.h>
#include <common/unicode/unistr.h>

extern "C" jstring Java_com_test_libicu_MainActivity_stringFromJNI( JNIEnv *env, jobject /* this */) {
    {
        std::string temp = std::string("aaabb");
        icu::UnicodeString aaa(temp.c_str(), "UTF-8");
        wchar_t uft32String[256] = {0};
        int utf32length = aaa.extract(0, aaa.length(), (char*)uft32String, "UTF-32");
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2], uft32String[3], uft32String[4], uft32String[5], uft32String[6]);
        utf32length/=4;
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2], uft32String[3], uft32String[4], uft32String[5], uft32String[6]);
    }

    {
        std::string temp = std::string("あ");
        icu::UnicodeString aaa(temp.c_str(), "UTF-8");
        wchar_t uft32String[256] = {0};
        int utf32length = aaa.extract(0, aaa.length(), (char*)uft32String, "UTF-32");
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2]);
        utf32length/=4;
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2]);
    }

    {
        std::string temp = std::string("丸の内署");
        icu::UnicodeString aaa(temp.c_str(), "UTF-8");
        wchar_t uft32String[256] = {0};
        int utf32length = aaa.extract(0, aaa.length(), (char*)uft32String, "UTF-32");
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2], uft32String[3], uft32String[4], uft32String[5]);
        utf32length/=4;
        __android_log_print(ANDROID_LOG_DEBUG, "aaaaa", "aaaaa utf32length=%d 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x 0x%04x", utf32length, uft32String[0], uft32String[1], uft32String[2], uft32String[3], uft32String[4], uft32String[5]);
    }

    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
