class Electronic:
    # constructor untuk inisialisasi atribut
    def __init__(self, id: int, name: str, type: str, price: float, image_path: str):
        self._id = id
        self._name = name
        self._type = type
        self._price = price
        self._image_path = image_path

    # getter untuk atribut
    def get_id(self) -> int:
        return self._id

    def get_name(self) -> str:
        return self._name

    def get_type(self) -> str:
        return self._type

    def get_price(self) -> float:
        return self._price

    def get_image_path(self) -> str:
        return self._image_path

    # setter untuk atribut
    def set_name(self, name: str) -> None:
        self._name = name

    def set_type(self, type: str) -> None:
        self._type = type

    def set_price(self, price: float) -> None:
        self._price = price

    def set_image_path(self, image_path: str) -> None:
        self._image_path = image_path