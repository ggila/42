<?PHP

class Targaryen
{
	public function resistsFire() {
		return FALSE;}

	public function getBurned() {
		return static::resistsFire() == TRUE ? 'emerges naked but unharmed' :
			'burns alive';
	}
	
	public function __toString () {
		return sprintf('%s', get_called_class());
	}
}
