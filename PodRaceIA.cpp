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

void next_input_must_be(string value) {
    string val;
    std::cin >> val;
    if (val.compare(value)) {
        std::cout << "expected input was " << value << "instead of " << val <<std::endl;
        exit(0);
    }
}

void read_dimensions(char parts[]) {
    WIDTH = int(parts[1]);
    HEIGHT = int(parts[2]);
}


def read_nb_pods(char parts[]) {
    NB_PODS = int(parts[1]);
    if(debug)
        std::cout << "nb pods : " << NB_PODS << std::endl;
    //if debug:print("nb pods : ", NB_PODS, file=sys.stderr)
}
 

std::map<char,int>  read_list_of_circles(parts) {
    string userEntry;
    int nb = int(parts[1])
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
    

void read_walls(char parts[]){
    walls = read_list_of_circles(parts)
}

void read_checkpoints(char parts[]) {
    checkpoints = read_list_of_circles(parts)
    if(debug) {
        std::cout << "checkpoints : " << checkpoints << std::endl;
    }
}




void dot(int a, int b) {
    // Loop
    return sum(x*y for x,y in zip(a,b))
}



def get_turn(pod, cp):
        vec = (cp["x"]-pod["x"],cp["y"]-pod["y"])
        angle = (360+math.degrees(math.atan2(vec[1], vec[0])))%360
        return -(pod["dir"]-angle)/2
    

def get_trust(pod, cp):
        vec = (cp["x"]-pod["x"],cp["y"]-pod["y"])
        normvec = .00001+dot(vec,vec)**.5
        vec = (vec[0]/normvec,vec[1]/normvec)
        speed = (pod["vx"],pod["vy"])
        normspeed = .00001+dot(speed,speed)**.5
        speed = (speed[0]/normspeed,speed[1]/normspeed)
        if dot(vec, speed) > 0.5:
            if normspeed > MAX_SPEED:
                return 0
            if normspeed < MIN_SPEED:
                return MAX_TRUST
        trust = normvec**EXPO
        if trust > MAX_TRUST:
            return MAX_TRUST
        return trust
    


def check(i):
    pod = pods[i]
    cp = checkpoints[cur_cp[i]]
    vec = (cp["x"]-pod["x"],cp["y"]-pod["y"])
    if dot(vec, vec) < cp["radius"]**2:
        cur_cp[i]+=1



if len(sys.argv)>1:
    MAX_TRUST = float(sys.argv[1])
if len(sys.argv)>2:
    EXPO = float(sys.argv[2])
if len(sys.argv)>3:
    MIN_SPEED = float(sys.argv[3])
if len(sys.argv)>4:
    MAX_SPEED = float(sys.argv[4])


settings = {
    "DIMENSIONS":read_dimensions,
    "WALLS":read_walls,
    "CHECKPOINTS":read_checkpoints,
    "NB_PODS":read_nb_pods
}

next_input_must_be("START player")
player = int(input())
next_input_must_be("STOP player")


next_input_must_be("START settings")
line = input()
while line != "STOP settings":
    parts = line.split()
    settings[parts[0]](parts)
    line = input()
    
pods = []
cur_cp = [0]*NB_PODS
turn = 1
while True:
    next_input_must_be("START turn")
    end = "STOP turn"
    pods = []
    line = input()
    while line != end:
        play,pod,x,y,vx,vy,direction, health = map(float, line.split())

        if debug:print(play,pod,x,y,vx,vy,direction, health, file=sys.stderr)
        if play == player:
            pods.append({
                "x":x,
                "y":y,
                "vx":vx,
                "vy":vy,
                "dir":direction,
                "health":health
                }) 
        line = input()

    if debug:print(pods, file=sys.stderr)
    if debug:print(checkpoints, file=sys.stderr)
        
    print("START action")
    for i in range(NB_PODS):
        check(i)
        if debug:print("debug IA : ",get_turn(pods[i], checkpoints[cur_cp[i]]),
             get_trust(pods[i], checkpoints[cur_cp[i]]), end=";", file=sys.stderr)
        
        print(get_turn(pods[i], checkpoints[cur_cp[i]]),
             get_trust(pods[i], checkpoints[cur_cp[i]]), end=";")
        
    print("")
    print("STOP action")
    turn += 1
    