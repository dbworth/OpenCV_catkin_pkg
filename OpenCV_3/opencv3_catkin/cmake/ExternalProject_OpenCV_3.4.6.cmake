#
# OpenCV 3.4.6
#

SET(CONTRIB_NAME "opencv3_contrib")
ExternalProject_Add(${CONTRIB_NAME}
  URL https://github.com/opencv/opencv_contrib/archive/3.4.6.zip
  URL_MD5 49646d4ba076b0fb6e1cd26f6aee8485
  SOURCE_DIR ${CONTRIB_NAME}_src
  UPDATE_COMMAND ""
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
)

SET(OPENCV_SRC_PATH "opencv3_src")
SET(OPENCV_BUILD_PATH "opencv3_build")
ExternalProject_Add(opencv3_src
  DEPENDS ${CONTRIB_NAME}
  URL https://github.com/opencv/opencv/archive/3.4.6.zip
  URL_MD5 19c2cbaa85746d45cffc5a0d7556730c
  UPDATE_COMMAND ""
  SOURCE_DIR ${OPENCV_SRC_PATH}
  BINARY_DIR ${OPENCV_BUILD_PATH}
  PATCH_COMMAND patch -p0 < ${CMAKE_SOURCE_DIR}/patches/fix_python_discovery.patch
  CONFIGURE_COMMAND cd ../${OPENCV_BUILD_PATH} && cmake
    -DOPENCV_EXTRA_MODULES_PATH=../${CONTRIB_NAME}_src/modules .
    -DOPENCV_ENABLE_NONFREE=ON
    -DWITH_TBB=ON
    -DBUILD_opencv_python2=ON
    -DBUILD_opencv_python3=ON
    -DWITH_GTK_2_X=ON  # Can't use GTK3 as it links against system protobuf.
    -DWITH_V4L=ON
    -DINSTALL_C_EXAMPLES=OFF
    -DINSTALL_PYTHON_EXAMPLES=OFF
    -DBUILD_EXAMPLES=OFF
    -DWITH_QT=OFF # Needed by clang under Ubuntu 14.04 and GTK_WIDGET(cvGetWindowHandle(...)) with gcc (image_view)
    -DWITH_OPENGL=ON
    -DWITH_VTK=ON
    -DENABLE_PRECOMPILED_HEADERS=OFF
    -DCMAKE_INSTALL_PREFIX=${CATKIN_DEVEL_PREFIX}
    -DBUILD_SHARED_LIBS=ON
    -DWITH_CUDA=OFF
    -DWITH_OPENCL=OFF
    -DBUILD_TESTS=OFF
    -DBUILD_opencv_ts=OFF
    -DBUILD_TESTS=OFF
    # opencv_contrib packages
    -DBUILD_opencv_dnn=OFF # Pulls in the system protobuf as a dependency!
    -DBUILD_opencv_dnns_easily_fooled=OFF
    -DBUILD_opencv_cnn_3dobj=OFF
    -DBUILD_opencv_aruco=ON
    -DBUILD_opencv_bgsegm=OFF
    -DBUILD_opencv_bioinspired=OFF
    -DBUILD_opencv_ccalib=OFF
    -DBUILD_opencv_contrib_world=OFF
    -DBUILD_opencv_datasets=OFF
    -DBUILD_opencv_dpm=OFF
    -DBUILD_opencv_face=OFF
    -DBUILD_opencv_fuzzy=OFF
    -DBUILD_opencv_freetype=OFF
    -DBUILD_opencv_hdf=OFF
    -DBUILD_opencv_line_descriptor=ON
    -DBUILD_opencv_matlab=OFF
    -DBUILD_opencv_optflow=OFF
    -DBUILD_opencv_plot=OFF
    -DBUILD_opencv_reg=OFF
    -DBUILD_opencv_rgbd=ON
    -DBUILD_opencv_saliency=ON
    -DBUILD_opencv_sfm=OFF
    -DBUILD_opencv_stereo=OFF
    -DBUILD_opencv_structured_light=OFF
    -DBUILD_opencv_surface_matching=OFF
    -DBUILD_opencv_text=OFF
    -DBUILD_opencv_tracking=OFF
    -DBUILD_opencv_xfeatures2d=ON
    -DBUILD_opencv_ximgproc=ON
    -DBUILD_opencv_xobjdetect=OFF
    -DBUILD_opencv_nonfree=ON
    -DBUILD_opencv_xphoto=OFF ../${OPENCV_SRC_PATH}
  BUILD_COMMAND cd ../${OPENCV_BUILD_PATH} && make -j8
  INSTALL_COMMAND cd ../${OPENCV_BUILD_PATH} && make install -j8
)
