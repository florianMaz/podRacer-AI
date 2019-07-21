#include <iostream>
#include <math.h>
#include <time.h>
#include <string>
#include "Pod.hpp"
#include <array>
#include <vector>
#include <sstream>
using namespace std;

// cd build && cmake --build . && cd .. && python3 GameDispatcher.py config.cfg
//g++ PodRaceIA.cpp -o podRacerIA
//python3 GameDispatcher.py config.cfg

bool debug = false;
int NB_PODS = 1;
int POD_RADIUS = 10;
float FRICTION = 0.005f;
int WIDTH = 800;
int HEIGHT = 800;
int TIME = 1;
int MAX_TURN = 15;
string player; // Nombre de joueur
float MAX_TRUST = 100.0f;
float EXPO = 1.2f;
float MAX_SPEED = 1000.0f;
float MIN_SPEED = 1.0f;
vector<Pod> pods;
//map<char,int> walls;
//map<char,int> checkpoints;
vector<int> cur_cp; // cp = checkpoints
vector<int> checkpoints;

vector<vector<int> > vCheckpoints;
vector<vector<int> > vWalls;
int turn = 0;


int settingsDimensions;
int settingsWalls;
int settingsCheckpoints;
int settingsNbPods;

int checkpointsX;
int checkpointsY;
int checkpointsRayon;

vector<string> string_split(const string& value, char delimiter)
{
    stringstream val_stream(value);
    string part;
    vector<string> parts;
    while (getline(val_stream, part, delimiter)) {
        parts.push_back(part);
    }
    return parts;
}

void next_input_must_be(string value) {
    string val;
    //cin >> val;
    getline(cin, val);
    cerr << "expected input need to be :  " << value << "given was : " << val <<endl;

    if (val.compare(value) != 0) {
        cerr << "expected input was " << value << "instead of " << val <<endl;
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
        cerr << "nb pods : " << NB_PODS << endl;
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

/*
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

    //def dot(a,b):
    //    return sum(x*y for x,y in zip(a,b))


    T result = 0;

    for(auto it = a.begin(), end = a.end(); it != end; it++) {
        for(auto it2 = b.begin(), end = b.end(); it2 != end; it2++) {
            result *= it * it2;
        }
    }

    return result;
}
*/

float get_turn(Pod pod) {
    vector<float> vector;

    float x = pod.getX();
    float y = pod.getY();

    //Add at the end of vector
    vector.push_back(checkpointsX - x);
    vector.push_back(checkpointsY - y);

    //Modulo in degrees of arc tangent in range radians of vector reference
    //float angle = fmodf(toDegrees(atan2f(vector.at(0), vector.at(1))), 360);
    //float angle = 0.5f;
    float radians = atan2f(vector.at(0), vector.at(1));
    float angle = fmod(radians * (180.0 / 3.141592653589793238463), 360);
    return -(pod.getDir() - angle) / 2;
}

/*
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
*/
/*
void check(int i){
    Pod pod = pods[i];
    vector<int> cp = checkpoints[cur_cp[i]];
    vector<float> vec = vector<float>();
    vec.push_back(cp[0]-pod.getX());
    vec.push_back(cp[1]-pod.getY());
    //if (dot(vec, vec) < powf(cp[3], 2)){
        //cur_cp[i]+=1;
        cur_cp.push_back(i);
    //}
}*/
void check(int i){
    Pod pod = pods[i];
    //cerr << "pod get x and y" << pod.getX() << " & " << pod.getY();
    //cerr << "checkpoints get x and y" << vCheckpoints[0][0] << " & " << vCheckpoints[0][1];
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
    //cin >> player;
    getline(cin, player);
    next_input_must_be("STOP player");


    next_input_must_be("START settings");
    //cin >> userInput;
    getline(cin, userInput);
    string checkpointsInput;
    string wallsInput;

    while (userInput.compare("STOP settings") != 0) {

        vector<string> result;
        result = string_split(userInput, ' ');
        /*istringstream iss(userInput);
        for(string userInput; iss >> userInput;) {
            result.push_back(userInput);
        }*/
        if (userInput.find("NB_PODS") != string::npos) {
            settingsNbPods = stoi(result[1]);//read_nb_pods(result[1]);
            // const int nbPods = stoi(result[1]);
        }

        if (userInput.find("DIMENSIONS") != string::npos) {
            WIDTH = stoi(result[1]);
            HEIGHT = stoi(result[2]);
        }
        if (userInput.find("WALLS") != string::npos) {
            for (size_t i = 0; i < stoi(result[1]); i++) { // result[1] => nombre de wall
                //cin >> wallsInput;
                getline(cin, wallsInput);
                vector<string> resultWallsInput;
                resultWallsInput = string_split(wallsInput, ' ');
                vector<int> walls; // tableau de walls
                walls.push_back(stoi(resultWallsInput[0]));
                walls.push_back(stoi(resultWallsInput[1]));
                walls.push_back(stoi(resultWallsInput[2]));
                vWalls.push_back(walls);
            }
        }

        if (userInput.find("CHECKPOINTS") != string::npos) {
            for (size_t i = 0; i < stoi(result[1]); i++) { // result[1] => nombre de checkpoints
                //cin >> checkpointsInput;
                getline(cin, checkpointsInput);
                vector<string> resultCheckpointsInput;
                resultCheckpointsInput = string_split(checkpointsInput, ' ');
                vector<int> checkpoints; // tableau de walls
                checkpoints.push_back(stoi(resultCheckpointsInput[0]));
                checkpoints.push_back(stoi(resultCheckpointsInput[1]));
                checkpoints.push_back(stoi(resultCheckpointsInput[2]));
                checkpointsX = stoi(resultCheckpointsInput[0]);
                checkpointsY = stoi(resultCheckpointsInput[1]);
                checkpointsRayon = stoi(resultCheckpointsInput[2]);
                vCheckpoints.push_back(checkpoints);
            }
        }
        //cin >> userInput;
        getline(cin, userInput);
    }


    //pods = vector<Pod>();
    //cur_cp = [0]*NB_PODS // ça j'ai pas compris
    turn = 1;
    vector<Pod> mPods = vector<Pod>();
    //Pod mPods[nbPods];
    while(1) {
        mPods.clear();

        next_input_must_be("START turn");

        string end = "STOP turn";
        //cin >> userInput;
        getline(cin, userInput);
        cerr << "after start turn : " <<userInput << endl;
        //cout << "START turn" << endl;
        while(userInput.compare(end) != 0) {
            vector<string> resultTurn;
            /*istringstream iss(userInput);
            for(string userInput; iss >> userInput;) {
                resultTurn.push_back(userInput);
            }*/
            resultTurn = string_split(userInput, ' ');
            //play=>result[0],pod=>result[1],x=>result[2],y=>result[3],
            // vx=>result[4],vy=>result[5],direction=>result[6], health=>result[7] = map(float, line.split())

            if(debug){
                //print(play,pod,x,y,vx,vy,direction, health, file=sys.stderr)
            }
            if(stoi(resultTurn[1]) == stoi(player)){ //play => case 1
                //if(true) {
                Pod pod = Pod(); //case 0
                pod.setX(stof(resultTurn[2]));
                pod.setY(stof(resultTurn[3]));
                pod.setVX(stof(resultTurn[4]));
                pod.setVY(stof(resultTurn[5]));
                pod.setDir(stof(resultTurn[6]));
                pod.setHealth(stof(resultTurn[7]));

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

                mPods.push_back(pod);
                // mPods[stoi(resultTurn[0])] = pod;
                // cin >> userInput;
            }

            getline(cin, userInput);
        }

        cout << "START action" << endl;
        cerr << "START action" << endl;

        for (int i = 0; i<settingsNbPods; i++){

            //check(i);
           // cout << get_turn(my[i], vCheckpoints[0]) << " " << pods[i].getVY();
            float podThrust = 10;
            //float currentDistance = getDistanceToCheckpoints(mPods[i]);
           /* if(currentDistance > previousDistance) {
                podThrust = -(2*podThrust);
            }*/
            //previousDistance = currentDistance;
            cout << get_turn(mPods[i]) << " " << podThrust;
            if((mPods[i].getX() > checkpointsX-checkpointsRayon && mPods[i].getX() < checkpointsX+checkpointsRayon)
            && (mPods[i].getY() > checkpointsY-checkpointsRayon && mPods[i].getY() < checkpointsY+checkpointsRayon)){
                cerr << "winner is the pod" << i << endl;
                exit(1);
            }
            if (i == (settingsNbPods - 1)) {
                cout << endl;
            } else {
                cout << ";";
            }
            if (debug){
                //print("debug IA : ",get_turn(pods[i], checkpoints[cur_cp[i]]),
                //  get_trust(pods[i], checkpoints[cur_cp[i]]), end=";", file=sys.stderr);}

            }
            //cout << get_turn(pods[i], cur_cp) << settingsDimensions << 0.5 << settingsCheckpoints << ";";
            //cout << get_turn(pods[i], checkpoints[cur_cp[i]], get_trust(pods[i], checkpoints[cur_cp[i]]), end=";"); // Je comprends pas quoi passer à get turn
            //print(get_turn(pods[i], checkpoints[cur_cp[i]]), get_trust(pods[i], checkpoints[cur_cp[i]]), end=";");
        }

        cout<<"STOP action"<<endl;
        cerr<<"STOP action"<<endl;

        turn += 1;
    }
}