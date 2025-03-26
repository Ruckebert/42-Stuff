/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:13:55 by aruckenb          #+#    #+#             */
/*   Updated: 2025/03/25 13:17:33 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	//Subject Test Given
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;

	std::cout << ++a << std::endl;

	std::cout << a << std::endl;

	std::cout << a++ << std::endl;

	std::cout << a << std::endl;
	
	std::cout << b << std::endl;
	
	std::cout << Fixed::max( a, b ) << std::endl;

	//My own tests
	std::cout << "\nNew tests\n";
		
	Fixed c( Fixed( 10) / Fixed( 2 ) );
	
	std::cout << c << std::endl;
	
	c = Fixed(10.5f) / Fixed(2);

	std::cout << c << std::endl;

	c = Fixed(10.5f) > Fixed(2);

	std::cout << c << std::endl;

	c = Fixed(10.5f) < Fixed(2);

	std::cout << c << std::endl;


	std::cout << a-- << std::endl;

	std::cout << a << std::endl;

	std::cout << --a << std::endl;

	std::cout << a << std::endl;

	Fixed const d( Fixed( 10.5f ) - Fixed( 2 ) );
		
	std::cout << d << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed const e( Fixed( 10.5f ) - Fixed( 2 ) );
	std::cout << e << std::endl;
	return 0;
}