
class contact:
    def __init__(self, id: int, name: str, address: str, phone: str, email: str) -> None:
        self.id = id
        self.name = name
        self.address = address
        self.phone = phone
        self.email = email

    def __str__(self) -> str:
        return f"ID: #{self.id} - {self.name}, {self.address}, {self.phone[:2]}-{self.phone[2:6]}-{self.phone[6:]}, {self.email}"

class node:
    def __init__(self, data: contact = None) -> None:
        self.data = data
        self.next = None

class linked_list:
    def __init__(self, ) -> None:
        self.header = node()

    def empty(self) -> bool:
        if self.header.next != None:
            return False
        return True

    def insert(self, data: contact) -> None:

        new_node: node = node(data)
        aux: node = self.header

        while aux.next != None:
            aux = aux.next

        aux.next = new_node

    def erase(self, name: str) -> None:
        
        current: node = self.header
        last: node = None

        while not self.empty():
            last = current
            current = current.next

            if current.data.name == name:
                last.next = current.next
                return

    def erase_all(self) -> None:
        self.header = node()

    def find(self, name: str) -> dict:
        
        current: node = self.header
        status: bool = False
        data: contact = None

        form: dict = {}

        while not self.empty():
            current = current.next
            if current.data.name == name:
                data = current.data
                status = True
                break

        form['status'] = status
        form['data'] = data
    
        return form

    def show_contacts(self) -> None:
        
        current: node = self.header

        while current.next != None:
            current = current.next
            print(current.data)