#include "java_api.h"
#include "proc4j_common.h"
#include <jni.h>

JNIEXPORT jobjectArray JNICALL Java_org_proc4j_ProcessesFunctions_list(JNIEnv* env, jobject obj) {
    /* Obtain fields & classes*/
    jclass process_class = (*env)->FindClass(env, "org/proc4j/ProcessInfoNative");
    jfieldID pid_field = (*env)->GetFieldID(env, process_class, "pid", "I");
    jfieldID name_field = (*env)->GetFieldID(env, process_class, "name", "Ljava/lang/String;"); 



    proc4j_process_list_t* list = proc4j_get_process_list();
    jobjectArray res;
    res = (*env)->NewObjectArray(env, list->len, process_class, 0);
    int i;
    for (i = 0 ; i < list->len; i++) {
        jobject p = (*env)->AllocObject(env, process_class);
        (*env)->SetObjectField(env, p, name_field, (*env)->NewStringUTF(env, list->processes[i].name));
        (*env)->SetIntField(env, p, pid_field, list->processes[i].id);
        (*env)->SetObjectArrayElement(env, res, i, p);

    }
    proc4j_process_list_free(list);
    return res;
}

JNIEXPORT jint JNICALL Java_org_proc4j_ProcessesFunctions_kill(JNIEnv* env, jclass cls, jint pid, jint sig) {
    return 0;
}

JNIEXPORT jint JNICALL Java_org_proc4j_ProcessesFunctions_currentPid(JNIEnv* env, jclass cls) {
    return 0;
}
