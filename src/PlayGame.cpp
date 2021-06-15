#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include "std_msgs/String.h"
#include "project1_pkg/my_msg.h"
#include <iostream>
#include <map>

using namespace std;


int main(int argc, char **argv){

    // Initialize a node
    ros::init(argc, argv, "Game");
    ros::NodeHandle nH;

    ros::Publisher pub = nH.advertise<project1_pkg::my_msg>("/custom_msg_topic", 10);
    ros::Rate loop_rate(1);
    
    project1_pkg::my_msg msg;

    int position;
    int symbol;

    // Initialize a map that maps position to the symbol at that position
    map<int, string> map;
    for(int i = 1; i <= 9; i++){

        map.insert(pair<int, string>(i, "empty"));
    }

    cout << "turn = 1 --> 'I-Shape' " << endl;
    cout << "turn = 2 --> 'Circle' " << endl;

    int turn = 1;  // (turn = 1 for I' and turn = 2 for circle)
    int moves = 0;

    for(int i = 0; i < 10; i++){      

        bool ctrl = false;

        while(!ctrl){

            int connections = pub.getNumSubscribers();

            if(connections > 0){

                cout << "\nIts your turn " << turn << "- choose position (1,2,3,4,5,6,7,8,9) = " << endl;
                cin >> position;

                msg.position = position;
                msg.symbol = turn;
                pub.publish(msg);
                ctrl = true;

            }
            else{

                loop_rate.sleep();
            }
            
        }

        map[position] = turn;
        moves++;

        // Check for victory
        if(moves >= 5){

            if(((map[1] == map[2]) && (map[2] == map[3])) && map[1] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[4] == map[5]) && (map[5] == map[6])) && map[4] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[7] == map[8]) && (map[8] == map[9])) && map[7] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[1] == map[4]) && (map[4] == map[7])) && map[1] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[2] == map[5]) && (map[5] == map[8])) && map[2] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[3] == map[6]) && (map[6] == map[9])) && map[3] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[1] == map[5]) && (map[5] == map[9])) && map[7] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }
            else if(((map[3] == map[5]) && (map[5] == map[7])) && map[3] != "empty"){

                cout << "\nGame Over" << endl;
                cout<< "Player "<< turn << " won !!" << endl;
                break;

            }

        }

        // If neither wins - Tie
        if(moves == 9){

            cout << "\nGame Over" << endl;
            cout << "It's a TIE !!" << endl;
            break;
        }

        if(turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }

    }

    
    ros::spinOnce();

    return 0;
}