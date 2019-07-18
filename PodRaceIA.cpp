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


void get_trust(Pod pod, array<int, 3>cp){
    vector<float> vec = vector<float>();
    vec.push_back(cp[0]-pod.getX());
    vec.push_back(cp[1]-pod.getY());

    float normvec = .00001+dot(vec,vec)**.5;
    vec.push_back(vec[0]/normvec);
    vec.push_back(vec[1]/normvec);

    vector<float> speed = vector<float>();
    speed.push_back(pod.getVX());
    speed.push_back(pod.getVY());

    float normspeed = .00001+dot(speed,speed)**.5;
    speed.push_back(speed[0]/normspeed);
    speed.push_back(speed[1]/normspeed);

    if (dot(vec, speed) > 0.5){
        if (normspeed > MAX_SPEED){
                    return 0;
            }
        if(normspeed < MIN_SPEED){
                    return MAX_TRUST;
            }
    }
    float trust = powf(normVec, EXPO);
    if(trust > MAX_TRUST){
        return MAX_TRUST
    }
    return trust
}

void check(int i){
    Pod pod = pods[i];
    array<int, 3> cp = checkpoints[cur_cp[i]];
    vector<float> vec = vector<float>();
    vec.push_back(cp[0]-pod.getX());
    vec.push_back(cp[1]-pod.getY());
    if (dot(vec, vec) < powf(cp[3], 2)){
        cur_cp[i]+=1;
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

