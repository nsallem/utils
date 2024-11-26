#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <random>

int main()
{
    // Define the point cloud type (XYZ type)
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);

    // Define random number generator for x and y
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis_x(-100.0, 100.0);
    std::uniform_real_distribution<> dis_y(-100.0, 100.0);

    // Number of points to generate
    int num_points = 10000; // You can change this number as needed

    // Generate points on the plane z = 0
    for (int i = 0; i < num_points; ++i)
    {
        pcl::PointXYZ point;
        point.x = dis_x(gen); // Random x between -100 and 100
        point.y = dis_y(gen); // Random y between -100 and 100
        point.z = 0.0f;       // z = 0 to represent a plane

        cloud->points.push_back(point); // Add the point to the cloud
    }

    // Set the cloud width and height (for PCL to recognize it correctly)
    cloud->width = num_points;
    cloud->height = 1;
    cloud->is_dense = true; // Mark cloud as dense (no NaNs)

    std::cout << "Point cloud generated with " << cloud->points.size() << " points." << std::endl;

    // Save the generated point cloud to a PCD file
    pcl::io::savePCDFileASCII("plane_point_cloud.pcd", *cloud);

    std::cout << "Point cloud saved to 'plane_point_cloud.pcd'" << std::endl;

    return 0;
}
