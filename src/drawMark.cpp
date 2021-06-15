#include "ros/ros.h"
#include "turtlesim/TeleportAbsolute.h"
#include "turtlesim/SetPen.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "project1_pkg/my_msg.h"
#include "geometry_msgs/Twist.h"

using namespace std;

int position_val = -1;
int symbol_val = -1;

ros::Publisher pub_shape;
ros::Subscriber sub;
ros::ServiceClient pen;
ros::ServiceClient move_abs;



void myTopicCallback(const project1_pkg::my_msg::ConstPtr& msg){
    
    position_val = msg->position;
    symbol_val = msg->symbol;

    turtlesim::SetPen penState;

    penState.request.r = 255;
    penState.request.g = 255;
    penState.request.b = 255;
    penState.request.width = 2;
    penState.request.off = 1;

    pen.call(penState);

    turtlesim::TeleportAbsolute coords;
    geometry_msgs::Twist draw_command;

    ros::Rate loop_rate(1);


// ********************************** For circle ************************************
    if(symbol_val == 2){
        
        if(position_val == 1){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 9.0;
            move_abs.call(coords);   // Move to the desired location
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;
            while(count != 3){
       
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;

                    }
                    else{

                        loop_rate.sleep();

                    }

                }

                count++;

            }

        }

        else if(position_val == 2){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 9.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
        
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
              

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 3){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 9.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
      
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
                

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 4){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 5.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;
            
            while(count != 3){
        
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
            

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 5){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 5.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
        
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
                     

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 6){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 5.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
        
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
                     
                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 7){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 1.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
      
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
          

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 8){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 1.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
     
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
      

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }
        else if(position_val == 9){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 1.0;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            // Draw a circle
            int count = 0;

            while(count != 3){
     
                draw_command.linear.x = 5.0;
                draw_command.linear.y = 0.0;
                draw_command.linear.z = 0.0;
                draw_command.angular.x = 0.0;
                draw_command.angular.y = 0.0;
                draw_command.angular.z = 6.0;

                bool ctrl_c = false;

                while(!ctrl_c){

                    int connections = pub_shape.getNumSubscribers();

                    if(connections > 0){

                        pub_shape.publish(draw_command); // Publish to turtlesim node
                        ctrl_c = true;
         

                    }
                    else{

                        loop_rate.sleep();

                    }

                }
                count++;

            }

        }

    }
    
     // ****************************** For 'I' ******************************************
    else{

        if(position_val == 1){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 8.5;
            move_abs.call(coords);   // Move to the desired location
            penState.request.off = 0;
            pen.call(penState);
            
       
            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
      

                }
                else{

                    loop_rate.sleep();

                }

            }

            

        }

        else if(position_val == 2){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 8.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
               

                }
                else{

                    loop_rate.sleep();

                }

            }


        }
        else if(position_val == 3){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 8.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
                 

                }
                else{

                    loop_rate.sleep();

                }

            }


        }
        else if(position_val == 4){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 5.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
               

                }
                else{

                    loop_rate.sleep();

                }

            }
         
        }
        else if(position_val == 5){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 5.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
           

                }
                else{

                    loop_rate.sleep();

                }

            }


        }
        else if(position_val == 6){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 5.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;

                }
                else{

                    loop_rate.sleep();

                }

            }

        }
        else if(position_val == 7){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 2.0;
            coords.request.y = 1.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;

                }
                else{

                    loop_rate.sleep();

                }

            }

        }
        else if(position_val == 8){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 6.0;
            coords.request.y = 1.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;

                }
                else{

                    loop_rate.sleep();

                }

            }
 
        }
        else if(position_val == 9){

            // Turn off the pen
            penState.request.off = 1;
            pen.call(penState);

            coords.request.x = 10.0;
            coords.request.y = 1.5;
            move_abs.call(coords);
            penState.request.off = 0;
            pen.call(penState);

            draw_command.linear.x = 0.0;
            draw_command.linear.y = 2.0;
            draw_command.linear.z = 0.0;
            draw_command.angular.x = 0.0;
            draw_command.angular.y = 0.0;
            draw_command.angular.z = 0.0;

            bool ctrl_c = false;

            while(!ctrl_c){

                int connections = pub_shape.getNumSubscribers();

                if(connections > 0){

                    pub_shape.publish(draw_command); // Publish to turtlesim node
                    ctrl_c = true;
                  

                }
                else{

                    loop_rate.sleep();

                }

            }

        }

    }

}



int main(int argc, char **argv){
    
    // Initialize a node
    ros::init(argc, argv, "turtle_mark");
    ros::NodeHandle nH;
    // For going to different points on the board
    move_abs = nH.serviceClient<turtlesim::TeleportAbsolute>("/turtle1/teleport_absolute");
    //For controlling the pen
    pen = nH.serviceClient<turtlesim::SetPen>("/turtle1/set_pen");
    // For publishing the drawn shapes 
    pub_shape = nH.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 10);
    // Subscribe to 'Game' node
    sub = nH.subscribe("/custom_msg_topic", 10, myTopicCallback);


    while(ros::ok()){

        ros::spin();
    }

    return 0;
}
