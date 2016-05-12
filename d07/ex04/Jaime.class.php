<?PHP

class Jaime extends Lannister
{
	public function getSize(){
		return 'Medium';}

	public function SleepWith($sexmate)
	{
		if (get_class($sexmate) === 'Tyrion')
			printf('Not even if I\'m drunk'.PHP_EOL);
		else if (get_class($sexmate) === 'Sansa')
			printf('Let\'s do this'.PHP_EOL);
		else if (get_class($sexmate) === 'Cersei')
			printf('With pleasure, but only in a tower in Winterfell, then'.PHP_EOL);
	}
/*	public function __construct() {
		parent::__construct();
		print('My name is Tyrion'.PHP_EOL);
	}
*/}

?>
