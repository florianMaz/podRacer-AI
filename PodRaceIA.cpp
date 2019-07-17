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

using namespace std;

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

template <typename T> T dot(vector<T> a, vector<T> b) {
    /*
    def dot(a,b):
        return sum(x*y for x,y in zip(a,b))
    */

    T result = 0;

    for(auto it = a.begin(), end = a.end(); it != end; it++) {
        for(auto it2 = b.begin(), end = b.end(); it2 != end; it2++) {
            result *= it * it2;
        }
    }

    return result;
}

def get_turn(pod, cp):
    vec = (cp["x"]-pod["x"],cp["y"]-pod["y"])
    angle = (360+math.degrees(math.atan2(vec[1], vec[0])))%360
    return -(pod["dir"]-angle)/2

float get_turn(Pod pod, array<int, 3> cp) {
    vector<T> vector = vector<float>();

    int x = pod.getX();
    int y = pod.getY();

    //Add at the end of vector
    vector.push_back(cp[0] - x);
    vector.push_back(cp[1] - y);

    //Modulo in degrees of arc tangent in range radians of vector reference
    float angle = fmodf(toDegrees(atan2f(vector.at(0), vector.at(1))), 360);

    return -(pod.getDir() - angle) / 2;
}



int main() {
    MAX_SPEED = 0.5;
    int settingsDimensions = read_dimensions(100, 100);
    int settingsWalls = read_walls(1);
    int settingsCheckpoints = read_checkpoints(1);
    int settingsNbPods = read_nb_pods(1);
    /*
    settings = {
            "DIMENSIONS":read_dimensions,
            "WALLS":read_walls,
            "CHECKPOINTS":read_checkpoints,
            "NB_PODS":read_nb_pods
    }
*/
    next_input_must_be("START player")
    player = int(input())
    next_input_must_be("STOP player")


    next_input_must_be("START settings")
    line = input()
    while (line != "STOP settings") {
        parts = line.split()
        settings[parts[0]](parts)
        line = input()
    }


    pods = []
    cur_cp = [0]*NB_PODS
    turn = 1
    while(1) {
                next_input_must_be("START turn")
                end = "STOP turn"
                pods = []
                line = input()
                while(line != end) {
                    play,pod,x,y,vx,vy,direction, health = map(float, line.split())

                    if(debug){
                        print(play,pod,x,y,vx,vy,direction, health, file=sys.stderr)
                    }
                    if(play == player){
                        pods.append({
                                            "x":x,
                                            "y":y,
                                            "vx":vx,
                                            "vy":vy,
                                            "dir":direction,
                                            "health":health
                                    })
                    }

                    line = input()
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

