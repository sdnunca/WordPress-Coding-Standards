<?php

__( "hell$varo", 'domain' ); // Bad, shouldn't use a string with variables

__( "hell\$varo", 'domain' ); // OK, Variable is not interpolated.
__( "hell\\$varo", 'domain' ); // Bad, is interpolated.
__( "hell\\\$varo", 'domain' ); // OK, variable is escaped.

__( $var, 'domain' ); // Bad, shouldn't use variables

__( 'string', SOMETHING ); // Bad, shouldn't use CONSTANTS

__( 'string' . $var, 'domain' ); // Bad, shouldn't use variable for string

__( $var . 'string', 'domain' ); // Bad, shouldn't use variable for string

__( SOMETHING, 'domain' ); // Bad, shouldn't use constant for string

__( 'string' . SOMETHING, 'domain' ); // Bad, shouldn't use constant for string

__( SOMETHING . 'string', 'domain' ); // Bad, shouldn't use variable for string

__( 'string', $domain ); // Bad, shouldn't use variable for domain

__( 'string', 'my' . $domain ); // Bad, shouldn't use variable for domain

__( 'string', $domain . 'domain' ); // Bad, shouldn't use variable for domain

__( 'string', 'domain' ); // Good

_x( 'string', 'context', 'domain' ); // Good

_x( 'string', $var, 'domain' ); // Bad, shouldn't use variable for context

_x( 'string', 'context' . $var, 'domain' ); // Bad, shouldn't use variable for context

_x( 'string', $var . 'context', 'domain' ); // Bad, shouldn't use variable for context

_x( 'string', SOMETHING, 'domain' ); // Bad, shouldn't use constant for context

_x( 'string', SOMETHING . 'context', 'domain' ); // Bad, shouldn't use constant for context

_x( 'string', 'context' . SOMETHING, 'domain' ); // Bad, shouldn't use constant for context

_n( 'I have %d cat.', 'I have %d cats.', $number ); // Bad, no text domain.
_n( 'I have %d cat.', 'I have %d cats.', $number, 'my-slug' ); // OK.
_n( 'I have %d cat.', 'I have %d cats.', $number, "illegal $string" ); // Bad.
_n( 'I have %d cat.', 'I have %d cats.', $number, SOMETHING ); // Bad.

_n_noop( 'I have %d cat.', 'I have %d cats.' ); // Bad, no text domain.
_n_noop( 'I have %d cat.', 'I have %d cats.', 'my-slug' ); // OK.
_n_noop( 'I have %d cat.', 'I have %d cats.', "illegal $string" ); // Bad.
_n_noop( 'I have %d cat.', 'I have %d cats.',  SOMETHING ); // Bad.

_nx( 'I have %d cat.', 'I have %d cats.', $number, 'Not really.' ); // Bad, no text domain.
_nx( 'I have %d cat.', 'I have %d cats.', $number, $context ); // Bad.
_nx( 'I have %d cat.', 'I have %d cats.', $number, 'Not really.', 'my-slug' ); // OK.
_nx( 'I have %d cat.', 'I have %d cats.', $number, $context, 'my-slug' ); // Bad.
_nx( 'I have %d cat.', 'I have %d cats.', $number, 'Not really.', "illegal $string" ); // Bad.
_nx( 'I have %d cat.', 'I have %d cats.', $number, 'Not really.', SOMETHING ); // Bad.

_nx_noop( 'I have %d cat.', 'I have %d cats.', 'Not really.' ); // Bad, no text domain.
_nx_noop( 'I have %d cat.', 'I have %d cats.', $context ); // Bad, no text domain, variable context.
_nx_noop( 'I have %d cat.', 'I have %d cats.', 'Not really.', 'my-slug' ); // OK.
_nx_noop( 'I have %d cat.', 'I have %d cats.', $context, 'my-slug' ); // Bad.
_nx_noop( 'I have %d cat.', 'I have %d cats.', 'Not really.', "illegal $string" ); // Bad.
_nx_noop( 'I have %d cat.', 'I have %d cats.', 'Not really.', SOMETHING ); // Bad.

translate( 'foo', 'bar' ); // Bad, low-level API function.
translate_with_gettext_context( 'foo', 'bar', 'baz' ); // Bad, low-level API function.

_( 'foo', 'bar' ); // Bad.

__( 'foo', 'bar', 'too-many-args' ); // Bad.
_x( 'string', 'context', 'domain', 'too-many-args' ); // Bad
_n( 'I have %d cat.', 'I have %d cats.', $number, 'my-slug', 'too-many-args' ); // Bad
_n_noop( 'I have %d cat.', 'I have %d cats.', 'my-slug', 'too-many-args' ); // Bad.
_nx_noop( 'I have %d cat.', 'I have %d cats.', 'Not really.', 'my-slug', 'too-many-args' ); // Bad.

// Make sure that multi-line string literals are accepted.
_nx( 'I have
%d cat.', 'I have
%d cats.', $number, 'Not
really.', 'my-
slug' ); // OK.

// Ensure lack of spaces doesn't cause i18n error.
_n_noop('I have %d cat.', 'I have %d cats.', 'my-slug'); // OK.

// Dollar sign in literal string is not interpolated, so OK.
_n_noop( 'I have %d cat.', 'I have %d cats.', 'literal-string-so-$variable-not-interpolated' ); // OK.