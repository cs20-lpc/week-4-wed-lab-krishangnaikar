template <typename T>
DoublyList<T>::DoublyList()
: header(new Node), trailer(new Node) {
    this->length = 0;
    header->next  = trailer;
    trailer->prev = header;
}

template <typename T>
DoublyList<T>::DoublyList(const DoublyList<T>& copyObj)
: header(new Node), trailer(new Node) {
    this->length = 0;
    header->next  = trailer;
    trailer->prev = header;
    copy(copyObj);
}

template <typename T>
DoublyList<T>& DoublyList<T>::operator=(const DoublyList<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
DoublyList<T>::~DoublyList() {
    clear();
    delete header;
    delete trailer;
    header = trailer = nullptr;
}

template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* n = new Node(elem);
    Node* temp = trailer->prev;
    n->prev = temp;
    n->next = trailer;
    temp->next = n;
    trailer->prev = n;

    this->length ++;

}

template <typename T>
void DoublyList<T>::clear() {
    for (Node* curr = nullptr; header->next != trailer; ) {
        curr = header->next->next;
        delete header->next;
        header->next = curr;
    }

    trailer->prev = header;
    this->length  = 0;
}

template <typename T>
void DoublyList<T>::copy(const DoublyList<T>& copyObj) {
    this->length   = copyObj.length;
    Node* myCurr   = header;
    Node* copyCurr = copyObj.header->next;

    while (copyCurr != copyObj.trailer) {
        Node* n      = new Node(copyCurr->value);
        myCurr->next = n;
        n->prev      = myCurr;
        myCurr       = n;
        copyCurr     = copyCurr->next;
    }

    myCurr->next  = trailer;
    trailer->prev = myCurr;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position >= this->length || position < 0) {
        throw string("Out of bounds");
    }
    if (position >= (this->length>>1)) {      // bit shifting is faster than // 2
        int num_backs = this->length - position;
        Node * curr = trailer;
        for (int i = 0; i < num_backs; i++) {
            curr = curr->prev;
        }
        return curr->value;

    } else {
        Node* curr = header->next;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        return curr->value;
    }
}

template <typename T>
int DoublyList<T>::getLength() const {
    return this->length;
}


template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
  if (position > this->length || position < 0) {
    throw string("Out of bounds");
  }
  if (position == this->length) {
    append(elem);
    return;
  }
  if (position >= (this->length >> 1)) {
    Node* curr = trailer;
    int steps = this->length-position;
    for (int i = 0; i<steps; i++) {
        curr = curr->prev;
    }
    Node* left = curr->prev;
    Node* n = new Node(elem);
    n->prev = left;
    n->next = curr;
    left->next = n;
    curr->prev = n;
    this->length ++;
  } else {
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    Node* left = curr->prev;
    Node* n = new Node(elem);
    n->prev = left;
    n->next = curr;
    left->next = n;
    curr->prev = n;
    this->length ++;


  }

}

template <typename T>
bool DoublyList<T>::isEmpty() const {
    return this->length  == 0
        && header->next  == trailer
        && trailer->prev == header;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    if (position >= this->length || position < 0) {
        throw string("Out of bounds");
    }

    if (position >= (this->length >> 1)) {
        Node* curr = trailer;
        int steps = this->length-position;
        for (int i = 0; i<steps; i++) {
            curr = curr->prev;
        }

        Node* left = curr->prev;
        Node* right = curr->next;

        left->next = right;
        right->prev = left;
        delete curr;
        this->length --;
    } else {
        Node* curr = header->next;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        Node* left = curr->prev;
        Node* right = curr->next;

        left->next = right;
        right->prev = left;
        delete curr;
        this->length --;
    }


}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) {
            return true;
        }
        curr = curr -> next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    if (position >= this->length || position < 0) {
    throw string("Out of bounds");
  }
  if (position >= (this->length >> 1)) {
    Node* curr = trailer;
    int steps = this->length-position;
    for (int i = 0; i<steps; i++) {
        curr = curr->prev;
    }
    curr->value = elem;
  } else {
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
  }
}

template <typename T>
ostream& operator<<(ostream& outStream, const DoublyList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }
    else {
        typename DoublyList<T>::Node* curr = myObj.header->next;
        while (curr != myObj.trailer) {
            outStream << curr->value;
            if (curr->next != myObj.trailer) {
                outStream << " <--> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}
