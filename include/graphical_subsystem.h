#ifndef ACID_INCLUDE_GRAPHICAL_SUBSYSTEM_H_
#define ACID_INCLUDE_GRAPHICAL_SUBSYSTEM_H_


#include <active_system.h>
#include <draw_system.h>
#include <camera_system.h>

class GraphSubsystem {
  public:
    GraphSubsystem() = default;
    ~GraphSubsystem() = default;

    void set_graph(GraphSubsystem* graph) {
        graphic = graph;
    }

    void set_camera(CameraSystem* cam) {
        camera = cam;
    }



  private:
    CameraSystem* camera;
    GraphSubsystem* graphic;
};


#endif  // ACID_INCLUDE_GRAPHICAL_SUBSYSTEM_H_
