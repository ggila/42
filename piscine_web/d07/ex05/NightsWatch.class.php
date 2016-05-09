<?PHP

class NightsWatch
{
	private $_fighters;

	public function recruit($fighter) {
		if (is_subclass_of($fighter, 'IFighter'))
			$this->_fighters[] = $fighter;
	}

	public function fight() {
		foreach($this->_fighters as $fighter)
			$fighter->fight();
	}

	public function __construct() {
		$this->_fighters = array();
	}
}

?>
