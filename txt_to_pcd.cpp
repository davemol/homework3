#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char **argv) 
{
  int width = 0;
  string line;
  vector<string> values;
 
  ifstream file(argv[1]);

  if (file.is_open()){

    while(getline(file,line) && line.length() != 0)
      width++;
    
    file.clear();
    file.seekg(0, ios::beg);

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZ>);
    cloud->width = width;
    cloud->height = 1;
    cloud->is_dense = false;
    cloud->points.resize(cloud->width * cloud->height);
 
    int index = 0;

    for(size_t i=0; i<cloud->points.size(); i++){
      getline(file,line);
      
      std::istringstream iss(line);
    
      for(;iss >> line;)
         values.push_back(line);
      
      cloud->points[i].x = strtof((values[index]).c_str(),0);
      cloud->points[i].y = strtof((values[index + 1]).c_str(),0);
      cloud->points[i].z = strtof((values[index + 2]).c_str(),0);
    
      index += 3;
    }
    file.close();
    pcl::io::savePCDFileASCII("MapPoints.pcd",*cloud);
  }
}
