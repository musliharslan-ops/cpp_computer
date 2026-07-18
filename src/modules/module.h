#ifndef MODULE_H
#define MODULE_H

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

class Module {
public:
    explicit Module(std::string name) : name_(std::move(name)) {}
    virtual ~Module() = default;

    // Combinational phase: compute outputs and next-state from inputs + state.
    virtual void comb() {}
 
    // Sequential phase: commit next-state into state.
    virtual void ff() {}

    virtual void reset() {}


protected:

private:
    std::string name_;
};


#endif