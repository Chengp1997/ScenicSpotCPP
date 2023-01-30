//
// Created by 陈格平 on 2023/1/28.
//

#ifndef SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
#define SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
#include "../utils/graph/Vertex.h"

class ScenicSpotVertex : public Vertex{
private:
    string spotName;//name of spot
    string intro;//intro of spot
    int welcome;//how popular
    bool relaxPlace;//have relax place
    bool restRoom;//have restRoom
public:
    void setSpotName(string spotName);
    void setIntro(string intro);
    void setWelcome(int welcome);
    void setRelaxPlace(bool relaxPlace);
    void setRestRoom(bool restRoom);

    string getSpotName();
    string getIntro();
    int getWelcome();
    bool hasRelaxPlace();
    bool hasRestRoom();
};


#endif //SENICSPOTMANAGEMENT_SCENICSPOTVERTEX_H
