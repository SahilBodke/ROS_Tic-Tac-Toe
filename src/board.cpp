#include "ros/ros.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/SetPen.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

using namespace std;

int main(int argc, char **argv){

    // Initialize a node
    ros::init(argc, argv, "turtle_draw");
    ros::NodeHandle nH;
    
    // For going to different points on the board
    ros::ServiceClient move_abs = nH.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
    
    // For controlling the pen
    ros::ServiceClient pen = nH.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
    
    // For publishing the drawn grid lines 
    ros::Publisher control_pub = nH.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
   
    // Boards dimensions
    int x_len = 12;
    int y_len = 12;
    ros::Rate loop_rate(1);

    // Service for controlling the pen
    turtlesim::SetPen pen_state;
    pen_state.request.r = 255;
    pen_state.request.g = 255;
    pen_state.request.b = 255;
    pen_state.request.width = 2;
    pen_state.request.off = 1;


    pen.call(pen_state); // Calling the service to implement the changes made to the pen


    turtlesim::TeleportAbsolute og_coords; // For origin coords
    turtlesim::TeleportAbsolute temp_coords;  
    og_coords.request.x = 0.0;
    og_coords.request.y = 0.0;
      
    
    // To actually draw the grid lines
    geometry_msgs::Twist control_command;
    
    bool control_var = false;

    while(!control_var){

        int connections = control_pub.getNumSubscribers();

        if(connections > 0){

            // Draw Grid lines
            for(int i = 1; i < 3; i++){

                pen_state.request.off = 1;
                pen.call(pen_state);

                move_abs.call(og_coords); // Return turtle to the origin
                temp_coords.request.x = static_cast<float>(x_len/3)*i;
                temp_coords.request.y = 0;
                move_abs.call(temp_coords);

                pen_state.request.off = 0;
                pen.call(pen_state);
                temp_coords.request.y = y_len;
                move_abs.call(temp_coords);
            }
            for(int i = 1; i < 3; i++){

                pen_state.request.off = 1;
                pen.call(pen_state);

                move_abs.call(og_coords); // Return turtle to the origin
                temp_coords.request.y = static_cast<float>(y_len/3)*i;
                temp_coords.request.x = 0;
                move_abs.call(temp_coords);
                
                pen_state.request.off = 0;
                pen.call(pen_state);
                temp_coords.request.x = x_len;
                move_abs.call(temp_coords);
            }

            control_var = true;
            pen_state.request.off = 1;
            pen.call(pen_state);

            move_abs.call(og_coords); // Return turtle to the origin

        }

    }

    while(ros::ok()){

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;  
}