#ifndef EventCallback_h
#define EventCallback_h

class EventCallback {
  public:
    virtual void callback(int payload) = 0;
};

#endif
