#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

// Implment Circular Doubly Linked List

typedef int Item;

struct Node {
    Item item;
    Node *next;
    Node *prev;

    Node(const Item &i, Node *nextnode = nullptr, Node *prevnode = nullptr){
        item = i;
        next = nextnode;
        prev = prevnode;
    }
};

class List {
    private:
        Node *head;
        int m_size;
        
    public:
        List(); 
        List(const List &lst); 
        ~List(); 
        bool empty() const; 
        size_t size() const; 
        void clear(); 
        Item &front(); 
        Item &back(); 
        void push_front(const Item &data); 
        void push_back(const Item &data); 
        void pop_front(); 
        void pop_back(); 
        void insertAt(const Item &data, int index); 
        void removeAt(int index); 
        void removeAll(const Item &data); 
        void swap(List &lst); 
        void concat(List &lst); 
        List *copy(); 
        void append(Item vec[], int n); 
        bool equals(const List &lst) const; 
        void reverse(); 
        void merge(List &lst); 
        friend std::ostream &operator<<(std::ostream &out, const List &lst); 
        Item &operator[](int index); 
        List &operator=(const List &lst);
};

List::List() {
    head = nullptr;
    m_size = 0;
}

List::List(const List &lst) {
    if(lst.empty()) {
        head = nullptr;
        m_size = 0;
    }else{
        head = new Node(lst.head->item);
        head->next = head;
        head->prev = head;
        m_size = 1;
        Node *currente = lst.head->next;
        while(currente != lst.head) {
            push_back(currente->item);
            currente = currente->next;
        }
    }
}

List::~List() {
    clear();
}

bool List::empty() const {
    return head == nullptr;
}

size_t List::size() const {
    return m_size;
}

void List::clear() {
    if(!empty()) {
        Node *current = head->next;
        Node *next;
        while(current != head) {
            next = current->next;
            delete current;
            current = next;
        }
        delete head;
        head = nullptr;
        m_size = 0;
    }
}

Item& List::front() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->item;
}

Item& List::back() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    return head->prev->item;
}

void List::push_front(const Item &data) {
    // Verifica se o head é nulo
    if(empty()) {
        // Se sim, faz o head apontar para o novo node
        head = new Node(data);
        // head aponta para ele mesmo
        head->next = head;
        head->prev = head;
    }else{
        // Se não, pega o last node
        Node *last = head->prev;

        // Cria um newNode
        Node *newNode = new Node(data);

        // Faz o newNode next apontar para o head e newNode prev apontar para o last
        newNode->next = head;
        newNode->prev = last;

        // Faz o last next apontar para o newNode e o head prev apontar para o newNode
        last->next = newNode;
        head->prev = newNode;

        // Portanto, como o newNode se torna o primeiro da lista, o head passa a ser o newNode
        head = newNode;
    }
    m_size++;
}

void List::push_back(const Item &data) {
    if(empty()) {
        head = new Node(data);
        head->next = head;
        head->prev = head;
    }else{
        Node *last = head->prev;

        Node *newNode = new Node(data);
        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }
    m_size++;
}

// 1 - Henryck
void List::pop_front() {
    if(empty()) {
        throw std::out_of_range("List is empty");
    }
    else if(m_size == 1) {
        head = nullptr;
        m_size = 0;
    } else {
        Node *last = head->prev;
    
        head = head->next;
        head->prev = last;
        last->next = head;
        m_size--;
    }
}

// 2 - Vitor
void List::pop_back() {
    // Verifica se a lista está vazia
    if(empty()) {
        // Se sim, lança uma exceçao
        throw std::out_of_range("List is empty");
    }
    else if(m_size == 1) {
        // Caso o tamanho da lista for 1, então apenas remove o head e o tamanho passa a ser 0
        delete head;
        head = nullptr;
        m_size = 0;
    }else{
        // Caso contrario, recupera o last node
        Node *last = head->prev;

        // Faz o head apontar para o penultimo node da lista
        head->prev = last->prev;
        // Faz o penultimo node apontar de volta para o head
        last->prev->next = head;

        // Por fim, apaga o last node e atualiza o tamanho da lista
        delete last;
        last = nullptr;
        m_size--;
    }
}

// 3 - Vitor
void List::insertAt(const Item &data, int index) {
    // Verifica se o index é menor que 0 ou maior que o tamanho da lista
    if(index < 0 || index > m_size-1) {
        // Se sim, lança uma exceçao
        throw std::out_of_range("Index out of range");
    }else if(index == 0) {
        // Se o index for 0, entao chama o push_front para adionar o item no começo da lista
        push_front(data);
    }else{
        // Caso contrário, cria um newNode
        Node *newNode = new Node(data);
        // Cria um node auxiliar para pecorrer a lista
        Node *current = head;
        // Pecorre a lista até chegar no node que deve ser inserido
        for(int i = 0; i < index-1; i++) {
            current = current->next;
        }
        // Agora podemos inserir o newNode entre o current e o current->next
        current->next->prev = newNode;
        newNode->next = current->next;
        current->next = newNode;
        newNode->prev = current;
        // Atualiza o tamanho da lista
        m_size++;
    }
}

// 4 - Henryck
void List::removeAt(int index) {
    //verifica se o indice é vacilo
    if(index >= 0 && index <= m_size - 1) {
        
        if(index == 0) {
            //se o indice apontar para o primeiro nó, basta chamar a função pop_front();
            pop_front();
        } else if(index == m_size - 1) {
            //se o indice apontar para o último nó, basta chamar a função pop_back();
            pop_back();
        } else {
            Node *temp = head;
            //iremos inserir o nó que iremos remover dentro da variável temp
            //para isso, vamos utilizar um loop, que irá rodar até o indice indicado
            while(index > 0) {
                temp = temp->next;
                index--;
            }

            //em seguida, com o nó que queremos remover já dentro da variável temp
            //podemos prosseguir com a lógica de remoção do nó
            //obs: a lógica abaixo é aplicada para remover apenas nós centrais
            //pois nós do começo ou fim seriam removidos nas condições anteriores
            Node *tempPrev = temp->prev;
            tempPrev->next = temp->next;
            temp->next->prev = tempPrev;
            delete temp;
            m_size--;
        }
    } else {
        throw std::out_of_range("Index out of range");
    }
}

// 5 - Vitor
void List::removeAll(const Item &data) {
    // Verifica se a lista está vazia
    if(!empty()) {
        // Se não, se a lista tiver apenas um item e o item for o igual ao data, então remove o head e o tamanho passa a ser 0
        if(m_size == 1 && head->item == data) {
            delete head;
            head = nullptr;
            m_size = 0;
        }else{
            /**
             * Caso contrário, cria um node auxiliar para percorrer a lista
             * e um node temporario para guardar o que vai ser removido.
             */
            Node *current = head->next;
            Node *temp = nullptr;
            /**
             * Pecorre a lista verificando se o item do node atual é igual ao data
             * Se sim, então temp recebe o current
             * Conecta o anterior do current com o seguinte do current
             * Current aponta para o proximo node
             * Deleta o temp e atualiza o tamanho da lista
             */
            while(current != head){
                if(current->item == data) {
                    temp = current;
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                    current = current->next;
                    delete temp;
                    m_size--;
                }else{
                    current = current->next;
                }
            }
            /**
             * Current chegou no head, então verifica se o item do head é igual ao data
             * Se sim, aplica os passos anteriores
             */
            if(current->item == data) {
                temp = current;
                current->prev->next = current->next;
                current->next->prev = current->prev;
                head = current->next;
                delete temp;
                m_size--;
            }
            // Caso a lista tenha ficado vazia, entao head recebe nullptr
            if(m_size == 0) {
                head = nullptr;
            }
        }
    }else{
        throw std::out_of_range("List is empty");
    }
}

// 6 - Vitor
void List::swap(List &lst) {
    if(!empty() && !lst.empty()) {
        Node *temp = head;
        head = lst.head;
        lst.head = temp;
        int aux = m_size;
        m_size = lst.m_size;
        lst.m_size = aux;
    }
}

// 7 - Vitor
void List::concat(List &lst) {
    if(!lst.empty()) {
        push_back(lst.head->item);
        Node *current = lst.head->next;
        while(current != lst.head) {
            push_back(current->item);
            current = current->next;
        }
        lst.clear();
    }
}

// 8 - Henryck
List *List::copy() {
    //cria uma nova lista
    List *copy = new List();

    //verifica se a lista que queremos duplicar está vazia
    if(empty()) {
        return copy;
    }

    //adicionamos o head a nossa lista que receberá a cópia, através da função push_back
    copy->push_back(head->item);
    Node* current = head->next;

    //agora iremos andar por toda a nossa lista, sendo que para cada nó da nossa atual lista
    //iremos realizar o push_back do nó para a lista copy
    while(current != head) {
        copy->push_back(current->item);
        current = current->next;
    }
    
    return copy;
}

// 9 - Vitor
void List::append(Item vec[], int n) {
    for(int i=0; i<n; i++) {
        push_back(vec[i]);
    }
}

// 10 - Henryck
bool List::equals(const List &lst) const {
    if(empty() && lst.empty()) {
        //verifica se as listas estão vazias
        return true;
    } else if(m_size != lst.m_size) {
        //verifica se o tamanho das listas são diferentes
        return false;
    } else {
        //verifica o head antes de iniciar o loop, visto que o loop não irá verificar o head
        if(head->item == lst.head->item) {
            //cria duas variáveis, para que com elas possamos percorrer os nós das duas listas
            Node *current = head->next;
            Node *lstCurrent = lst.head->next;
            //percorre todos os nós de ambas as listas, e verifica se são iguais
            while(current != head) {
                if(current->item != lstCurrent->item){
                    //caso algum nó seja diferente do outro, irá retornar falso
                    return false;
                }
                //avança os nós para o próximo
                current = current->next;
                lstCurrent = lstCurrent->next;
            }
            return true;
        }
    }
    return false;
}

// 11 - Vitor
void List::reverse() {
    // Verifica se a lista nao esta vazio ou se tem apenas um item
    if(!empty() || m_size != 1){
        // Cria um node auxiliar para percorrer a lista e um temporario para guardar o que vai ser trocado
        Node *current = head->next;
        Node *temp = nullptr;
        /**
         * Pecorre a lista
         * troca o next do current com o prev do current,
         * assim, o proximo do current passa a ser o anterior do current
         * e o anterior do current passa a ser o proximo do current
         */
        while(current != head) {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        }
        // Current recebe o ultimo node da lista
        // Head recebe current, passando ser o primeiro node da lista
        current->next = head->prev;
        current->prev = head->next;
        head = current->next;
    }
}

//Henryck
void List::merge(List &lst) {
    if(lst.empty()) {
        throw std::out_of_range("the list passed is empty");
    } else if(empty()) {
        *this = lst;
        lst.clear();
    } else {
        Node *current = lst.head;
        int count = 0;
        //vamos inserir os números da segunda lista que couberem entre os números da primeira lista
        for(int i = 1; i < m_size; i+=2) {
            //como o m_size aumenta em cada inserção, será necessário que 
            //ao final de cada loop, a variável i, some mais dois
            insertAt(current->item, i);
            current = current->next;
            count++;
        }

        //caso ainda haja números na segunda lista, iremos realizar apenas o push_back deles
        if(count < lst.m_size) {
            for(int i = 0; i < lst.m_size-count; i++) {
                push_back(current->item);
                current = current->next;
            }
        }
        lst.clear();
    }
}

// 12 - Henryck
std::ostream &operator<<(std::ostream &out, const List &lst) {
    if(lst.empty()) {
        return out;
    }

    Node *current = lst.head->next;

    out << lst.head->item << " ";
    while(current != lst.head) {
        out << current->item << " ";
        current = current->next;
    }
    return out;
}

// 13 - Henryck
Item &List::operator[](int index) {
    if(empty() || index >= m_size || index < 0) {
        throw std::out_of_range("Index out of range");
    } else if(index == 0) {
        return front();
    } else if(index == m_size - 1) {
        return back();
    } else {
        Node* temp = head;
        while(index > 0) {
            temp = temp->next;
            index--;
        }

        return temp->item;
    }
}

// 14 - Henryck
List &List::operator=(const List &lst) {
    //iremos iniciar limpando a lista na qual recebera lst
    clear();
    if(lst.empty()) {
        return *this;
    }
    push_back(lst.head->item);
    //após isso, iremos apenas percorrer toda a lista lst, fazendo o pushBack de todos os seus elementos
    //dentro da lista que limpamos
    Node* current = lst.head->next;
    while(current != lst.head) {
        push_back(current->item);
        current = current->next;
    }

    return *this;
}

#endif
