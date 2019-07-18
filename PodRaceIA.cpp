#include <iostream>
#include <math.h>
#include <time.h>   
#include <string>
#include "Pod.hpp"
#include <array>
#include <vector>
using namespace std;

bool debug = false;
int NB_PODS = 1;
int POD_RADIUS = 10;
float FRICTION = 0.005;
int WIDTH = 800;
int HEIGHT = 800;
int TIME = 1;
int MAX_TRUST = 100;
int MAX_TURN = 15;
int player = 1; // Nombre de joueur
float MAX_TRUST = 100.0;
float EXPO = 1.2;
float MAX_SPEED = 1000.0;
float MIN_SPEED = 1.0;
vector<Pod> pods;
//map<char,int> walls;
//map<char,int> checkpoints;

void next_input_must_be(string value) {
    string val;
    cin >> val;
    if (val.compare(value)) {
        cout << "expected input was " << value << "instead of " << val <<endl;
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
        cout << "nb pods : " << NB_PODS << endl;
    //if debug:print("nb pods : ", NB_PODS, file=sys.stderr)
}
 
/*
map<char,int> read_list_of_circles(int nbCircles) {
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
        l.insert (std::pair<char,int>('x',stoi(result[0])));
        l.insert (std::pair<char,int>('y',stoi(result[1])));
        l.insert (std::pair<char,int>('radius',stoi(result[2])));
    }
    return l;
}*/
    

void read_walls(int nbCircles){
    walls = 2;//read_list_of_circles(nbCircles)
}

void read_checkpoints(int nbCircles) {
    checkpoints = 2//read_list_of_circles(nbCircles)
    if(debug) {
        cout << "checkpoints : " << checkpoints << endl;
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


float get_trust(Pod pod, array<int, 3>cp){
    vector<float> vec = vector<float>();
    vec.push_back(cp[0]-pod.getX());
    vec.push_back(cp[1]-pod.getY());
    float normvec;
    normvec = 0.00001+dot(vec,vec)*0.5;//.00001+dot(vec,vec)**.5;
    vec.push_back(vec[0]/normvec);
    vec.push_back(vec[1]/normvec);


    vector<float> speed = vector<float>();
    speed.push_back(pod.getVX());
    speed.push_back(pod.getVY());

    float normspeed = 0.00001+dot(speed,speed)*0.5;//.00001+dot(speed,speed)**.5;
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
        return MAX_TRUST;
    }
    return trust;
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


int main(int argc, char const *argv[]) {
    MAX_SPEED = 0.5;
    string userInput;

    /*
    settings = {
            "DIMENSIONS":read_dimensions,
            "WALLS":read_walls,
            "CHECKPOINTS":read_checkpoints,
            "NB_PODS":read_nb_pods
    }
*/
    if (argc > 1) {
        MAX_TRUST = atoi(argv[1]);
    }
    if (argc > 2) {
        EXPO = atoi(argv[2]);
    }
    if (argc > 3) {
        MIN_SPEED = atoi(argv[3]);
    }
    if (argc > 4) {
        MAX_SPEED = atoi(argv[4]);
    }
    next_input_must_be("START player");
    cin >> player;
    next_input_must_be("STOP player");


    next_input_must_be("START settings");
    cin >> userInput;
    while (userInput.compare("STOP settings") != 0) {
        vector<string> result;
        istringstream iss(userInput);
        for(string userInput; iss >> userInput;) {
            result.push_back(userInput);
        }
        int settingsDimensions = 100;//read_dimensions(result[0], result[1]);
        int settingsWalls = 1;//read_walls(result[2]);
        int settingsCheckpoints = 1;//read_checkpoints(result[3]);
        int settingsNbPods = 1;//read_nb_pods(result[4]);
        cin >> userInput;
    }


    pods = vector<Pod>();
    cur_cp = [0]*NB_PODS // ça j'ai pas compris
    turn = 1
    while(1) {
        next_input_must_be("START turn");
        string end = "STOP turn";
        cin >> userInput;
        while(userInput.compare(end) != 0) {
            vector<string> resultTurn;
            istringstream iss(userInput);
            for(string userInput; iss >> userInput;) {
                resultTurn.push_back(userInput);
            }
            //play=>result[0],pod=>result[1],x=>result[2],y=>result[3],
            // vx=>result[4],vy=>result[5],direction=>result[6], health=>result[7] = map(float, line.split())

            if(debug){
                //print(play,pod,x,y,vx,vy,direction, health, file=sys.stderr)
            }
            if(play == player){
                Pod pod = new Pod();
                pod.setX(stof(result[2]));
                pod.setY(stof(result[3]));
                pod.setVX(stof(result[4]));
                pod.setVY(stof(result[5]));
                pod.setDir(stof(result[6]));
                pod.setHealth(stof(result[7]));
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
            pods.push_back(pod);
            cin >> userInput;
        }


        if (debug){
            cout << pods;
            //print(pods, file=sys.stderr)
        }
        if(debug){
            //print(checkpoints, file=sys.stderr)
        }

        print("START action")
        for (int i = 0; i<NB_PODS; i++){

            check(i);
            if (debug){
                //print("debug IA : ",get_turn(pods[i], checkpoints[cur_cp[i]]),
                //  get_trust(pods[i], checkpoints[cur_cp[i]]), end=";", file=sys.stderr);}

            }
            cout << get_turn(pods[i] << settingsDimensions << get_trust(pods[i]) << settingsCheckpoints << ";";
            //cout << get_turn(pods[i], checkpoints[cur_cp[i]], get_trust(pods[i], checkpoints[cur_cp[i]]), end=";"); // Je comprends pas quoi passer à get turn
            //print(get_turn(pods[i], checkpoints[cur_cp[i]]), get_trust(pods[i], checkpoints[cur_cp[i]]), end=";");
        }

        cout<<("")
        cout<<("STOP action")
        turn += 1
    }


}

