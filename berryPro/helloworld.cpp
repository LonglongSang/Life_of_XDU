#include "C:\Program Files (x86)\Intel RealSense SDK 2.0 (Win7)\include\librealsense2\rs.hpp"




rs2::pipeline p;
void startup()
{
    p.start();
    rs2::frameset frames = p.wait_for_frames();
    rs2::depth_frame d_frames = frames.get_depth_frame();

    float width = d_frames.get_width();
    float height = d_frames.get_height();

}

int main()
{
    
}