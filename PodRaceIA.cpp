#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <string>

bool debug = false;
int NB_PODS = 3;
int POD_RADIUS = 10;
int FRICTION = 0.005;
int WIDTH = 800;
int HEIGHT = 800;
int TIME = 1;
int MAX_TRUST = 100;
int MAX_TURN = 15;
int player = 1; // Nombre de joueur

void next_input_must_be(string value) {
    string val;
    std::cin >> val;
    if (val.compare(value)) {
        std::cout << "expected input was " << value << "instead of " << val <<std::endl;
        exit(0);
    }
}

void read_dimensions(int width, int height) {
    WIDTH = width;
    HEIGHT = height;
}


void read_nb_pods(int nbPods) {
    NB_PODS = nbPods;
    if(debug)
        std::cout << "nb pods : " << NB_PODS << std::endl;
    //if debug:print("nb pods : ", NB_PODS, file=sys.stderr)
}
 

std::map<char,int>  read_list_of_circles(int nbCircles) {
    string userEntry;
    int nb = nbCircles;
    std::map<char,int> l;
    for (size_t i = 0; i < nb; i++)
    {
        std::cin >> userEntry;
        std::vector<std::string> result;
        std::istringstream iss(userEntry);
        for(std::string userEntry; iss >> userEntry;) {
            result.push_back(userEntry);
        }
        l.insert (std::pair<char,int>('x',result[0]));
        l.insert (std::pair<char,int>('y',result[1]));
        l.insert (std::pair<char,int>('radius',result[2]));
    }
    return l;
}
    

void read_walls(int nbCircles){
    walls = read_list_of_circles(nbCircles)
}

void read_checkpoints(int nbCircles) {
    checkpoints = read_list_of_circles(nbCircles)
    if(debug) {
        std::cout << "checkpoints : " << checkpoints << std::endl;
    }
}


int main(char args[]) {
    MAX_SPEED = 0.5;
    String userInput;

    /*
    settings = {
            "DIMENSIONS":read_dimensions,
            "WALLS":read_walls,
            "CHECKPOINTS":read_checkpoints,
            "NB_PODS":read_nb_pods
    }
*/
    next_input_must_be("START player")
    cin >> player;
    next_input_must_be("STOP player")


    next_input_must_be("START settings")
    cin >> userInput;
    while (userInput != "STOP settings") {
        std::vector<std::string> result;
        std::istringstream iss(userInput);
        for(std::string userInput; iss >> userInput;) {
            result.push_back(userInput);
        }
        int settingsDimensions = read_dimensions(result[0], result[1]);
        int settingsWalls = read_walls(result[2]);
        int settingsCheckpoints = read_checkpoints(result[3]);
        int settingsNbPods = read_nb_pods(result[4]);
        cin >> userInput;
    }


    array<Pod> pods = array<Pod>();
    cur_cp = [0]*NB_PODS
    turn = 1
    while(1) {
                next_input_must_be("START turn")
                end = "STOP turn"
                array<Pod> pods = array<Pod>();
                cin >> userInput;
                while(line != end) {
                    play,pod,x,y,vx,vy,direction, health = map(float, line.split())

                    if(debug){
                        print(play,pod,x,y,vx,vy,direction, health, file=sys.stderr)
                    }
                    if(play == player){
                        Pod pod = new Pod();
                        pod.setX(x);
                        pod.setY(y);
                        pod.setVx(vx);
                        pod.setVy(vy);
                        pod.setVy(setDir);
                        pod.setHealth(health);
                        /*
                        pods.append({
                                            "x":x,
                                            "y":y,
                                            "vx":vx,
                                            "vy":vy,
                                            "dir":direction,
                                            "health":health
                                    })
                                    */
                    }

                    cin >> userInput;
                }


                if (debug){
                    print(pods, file=sys.stderr)
                }
                if(debug){
                    print(checkpoints, file=sys.stderr)
                }

                print("START action")
                for (i in range(NB_PODS)){

                    check(i);
                    if (debug){print("debug IA : ",get_turn(pods[i], checkpoints[cur_cp[i]]),
                            get_trust(pods[i], checkpoints[cur_cp[i]]), end=";", file=sys.stderr);}

                    print(get_turn(pods[i], checkpoints[cur_cp[i]]), get_trust(pods[i], checkpoints[cur_cp[i]]), end=";");
                }

                print("")
                print("STOP action")
                turn += 1
    }


}

