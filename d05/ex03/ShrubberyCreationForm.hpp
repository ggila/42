/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:48:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 20:47:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define  SHRUBERRYCREATIONFORM_HPP

# define ASCII_tree "\
         $%^%&(^      *(^(*(()     $%^%&(^                 $%^%&(^        \n\
    /&(^(*(*&^(&^(&(\\*&^$%*(((/&(^(*(*&^(&^(&(\\       /&(^(*(*&^(&^(&(\\  \n\
  /&(^%%(^%(^&%&^%*&*\\&*(^%(/&(^%%(^%(^&%&^%*&*\\    /&(^%%(^%(^&%&^%*&*\\\n \
 <&#^^(*&^%^&$%^$#^^#^>^%&(<&#^^(*&^%^&$%^$#^^#^>  <&#^^(*&^%^&$%^$#^^#^> \n\
<&&#^^(*&^%^&$%^$#^^#^#>$%<&&#^^(*&^%^&$%^$#^^#^#><&&#^^(*&^%^&$%^$#^^#^#>\n\
 <&#^^(*&^%^&$%^$#^^#^>%^$^<&#^^(*&^%^&$%^$#^^#^>  <&#^^(*&^%^&$%^$#^^#^> \n\
   \\(*&^(*%(^%(^%^&(?>*&^%&**\(*&^(*%(^%(^%^&(?>     \(*&^(*%(^%(^%^&(?>  \n\
     <(*&^(*&^()&^?/&%$&^%$^$^ <(*&^(*&^()&^?/         <(*&^(*&^()&^?/    \n\
      \\(*&^^%*^%(/  \\(*&^^%*^%(/\\(*&^^%*^%(/            \\(*&^^%*^%(/    \n\
        |#@#$$#|      |#@#$$#|    |#@#$$#|                |#@#$$#|        \n\
        <*@#(*#|      <*@#(*#|    <*@#(*#|                <*@#(*#|        \n\
        |#%$^$#|      |#%$^$#|    |#%$^$#|                |#%$^$#|        \n\
        |#%)(*&>      |#%)(*&>    |#%)(*&>                |#%)(*&>        \n\
        |(*&%##|      |(*&%##|    |(*&%##|                |(*&%##|        \n\
        |#%@&$#|      |#%@&$#|    |#%@&$#|                |#%@&$#|        \n\
        |#%#^$#|      |#%#^$#|    |#%#^$#|                |#%#^$#|   \\/   \n\
  @     <#*%@$#|      <#*%@$#|    <#*%@$#|     $          <#*%@$#|   \\/   \n\
 \\|/    |#%#^$#|      |#%#^$#|    |#%#^$#|    \\|/         |#%#^$#|   \\/   \n"

# include <iostream>
# include <stdexcept>
# include <string>
# include <fstream>
# include "Form.hpp"

class ShruberryCreationForm: public AForm
{
	public:
int			getExec(void) const;
std::string	getTarget(void) const;
			ShruberryCreationForm(std::string target);
void		execute(Bureaucrat const &B) const;

	private:
			std::string			_target;
			int					_exec;

			ShruberryCreationForm();
			ShruberryCreationForm(ShruberryCreationForm &S);
			ShruberryCreationForm	&operator=(ShruberryCreationForm &S);
};

std::ostream				&operator<<(std::ostream &o, 
									ShruberryCreationForm const &S);

#endif
