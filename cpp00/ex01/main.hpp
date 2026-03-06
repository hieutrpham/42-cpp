/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trupham <trupham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:00:07 by trupham           #+#    #+#             */
/*   Updated: 2026/03/06 10:03:17 by trupham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>

#ifdef DEBUG
#define CONTACT_CAP 2
#else
#define CONTACT_CAP 8
#endif

#define FIELD_WIDTH 10

#endif // !MAIN_H
