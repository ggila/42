<?PHP

class House
{
	public function introduce(){
		printf('House %s of %s : "%s"',
				$this->getHouseName(),
				$this->getHouseSeat(),
				$this->getHouseMotto());
		print(PHP_EOL);
	}
}
