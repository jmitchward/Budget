#include "dataStructs.h"

Categories::Categories() {
}

bool Categories::addCategory(Category newCategory) {
    if (checkCategory(newCategory)) {
        categories.append(newCategory);
        return true;
    }
    else {
        return false;
    }
}

bool Categories::removeCategory(Category oldCategory) {
    if (checkCategory(oldCategory)) {
        categories.remove(categories.indexOf(oldCategory));
        return true;
    }
    else {
        return false;
    }
}

bool Categories::checkCategory(Category cat) {
    if (categories.contains(cat)) {
        return true;
    }
    else {
        return false;
    }
}

Members::Members() {
}

bool Members::addMember(Member newMember) {
    if(checkMember(newMember)) {
        members.append(newMember);
        return true;
    }
    else {
        return false;
    }

}

bool Members::removeMember(Member oldMember) {
    if (checkMember(oldMember)) {
        members.remove(members.indexOf(oldMember));
        return true;
    }
    else {
        return false;
    }
}

bool Members::checkMember(Member mem) {
    if (members.contains(mem)) {
        return true;
    }
    else {
        return false;
    }
}













