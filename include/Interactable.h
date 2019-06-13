/**
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @date 2019-04-19
 */

#ifndef INTERACTABLE_H_INCLUDED
#define INTERACTABLE_H_INCLUDED

#include <iostream>

class Interactable {
  public:
    Interactable() {
        in = &std::cin;
        out = &std::cout;
    }
    virtual ~Interactable() {}

    void setIn(std::istream& is) {
        in = &is;
    }
    void setOut(std::ostream& os) {
        out = &os;
    }

  protected:
    std::istream* in;
    std::ostream* out;

  private:
    Interactable(const Interactable&);
    Interactable& operator=(const Interactable& other);
};

#endif // INTERACTABLE_H_INCLUDED
