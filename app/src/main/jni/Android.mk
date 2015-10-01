LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := rdown
LOCAL_SRC_FILES := \
	rdown-jni.c \
	html/houdini_href_e.c \
	html/houdini_html_e.c \
	html/html.c \
	html/html_smartypants.c \
	s_src/autolink.c \
	s_src/buffer.c \
	s_src/markdown.c \
	s_src/stack.c \


LOCAL_C_INCLUDES := jni/src

include $(BUILD_SHARED_LIBRARY)