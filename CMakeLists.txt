project(pcl_intro)

cmake_minimum_required (VERSION 2.8) 
cmake_policy(SET CMP0015 NEW)

find_package(PCL 1.7 REQUIRED )
add_definitions(${PCL_DEFINITIONS})

find_package( OpenCV REQUIRED )

include_directories( ${PCL_INCLUDE_DIRS} 
                     ${OpenCV_INCLUDE_DIRS})

link_directories( ${PCL_LIBRARY_DIRS} 
                  ${OpenCV_LIB_DIR} )

add_executable(clustering clustering.cpp )
target_link_libraries( clustering ${PCL_LIBRARIES})
set_target_properties( clustering PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(txt_to_pcd txt_to_pcd.cpp )
target_link_libraries( txt_to_pcd ${PCL_LIBRARIES})
set_target_properties( txt_to_pcd PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
