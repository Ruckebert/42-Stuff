/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:13:55 by aruckenb          #+#    #+#             */
/*   Updated: 2025/04/08 10:47:32 by aruckenb         ###   ########.fr       */
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
	
	std::cout << "Division Test Int: " <<c << std::endl;
	
	c = Fixed(10.5f) / Fixed(2);

	std::cout << "Division Test Float: " << c << std::endl;

	c = Fixed(10.5f) > Fixed(2);

	std::cout << "Greater than: " << c << std::endl;

	c = Fixed(10.5f) < Fixed(2);

	std::cout << "Less than: " << c << std::endl;

	std::cout << "Minus Minus Before: " << a-- << std::endl;

	std::cout << "Minus Minus After: " << a << std::endl;

	std::cout << "Forward Minus Minus Before: " << --a << std::endl;

	std::cout << "Forward Minus Minus After: " << a << std::endl;

	Fixed const d( Fixed( 10.5f ) - Fixed( 2 ) );
		
	std::cout << "Subtraction: " << d << std::endl;

	std::cout << "Min: " << Fixed::min( a, b ) << std::endl;

	Fixed const e( Fixed( 10.5f ) + Fixed( 2 ) );

	std::cout << "Addition: " <<  e << std::endl;
	
	return 0;
}