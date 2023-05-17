#include "memory.h"

class CollectorV1 {
    public:
        // void collectGarbage();
        CollectorV1(Memory& memory);

        void countBlackNodes();
        // void markNodesWhite();
        // void markRootsBlack();
        void markNodesBlack();
        void newMarkingPhase();
        void collectingPahse();
        void collectGarbageNodes();
        void propagateWhite();
        void makeGrayWhite();
    private:
        int oldBlackCount, blackCount;
        Memory& memory;
        
};