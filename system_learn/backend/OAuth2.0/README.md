https://datatracker.ietf.org/doc/html/rfc6749#autoid-19

1.3.  Authorization Grant

   An authorization grant is a credential representing the resource
   owner's authorization (to access its protected resources) used by the
   client to obtain an access token.  This specification defines four
   grant types -- authorization code, implicit, resource owner password
   credentials, and client credentials -- as well as an extensibility
   mechanism for defining additional types.

1.3.1.  Authorization Code

   The authorization code is obtained by using an authorization server
   as an intermediary between the client and resource owner.  Instead of
   requesting authorization directly from the resource owner, the client
   directs the resource owner to an authorization server (via its
   user-agent as defined in [RFC2616]), which in turn directs the
   resource owner back to the client with the authorization code.

   Before directing the resource owner back to the client with the
   authorization code, the authorization server authenticates the
   resource owner and obtains authorization.  Because the resource owner
   only authenticates with the authorization server, the resource
   owner's credentials are never shared with the client.

   The authorization code provides a few important security benefits,
   such as the ability to authenticate the client, as well as the
   transmission of the access token directly to the client without
   passing it through the resource owner's user-agent and potentially
   exposing it to others, including the resource owner.

1.3.2.  Implicit

   The implicit grant is a simplified authorization code flow optimized
   for clients implemented in a browser using a scripting language such
   as JavaScript.  In the implicit flow, instead of issuing the client
   an authorization code, the client is issued an access token directly (as the result of the resource owner authorization).  The grant type
   is implicit, as no intermediate credentials (such as an authorization
   code) are issued (and later used to obtain an access token).

   When issuing an access token during the implicit grant flow, the
   authorization server does not authenticate the client.  In some
   cases, the client identity can be verified via the redirection URI
   used to deliver the access token to the client.  The access token may
   be exposed to the resource owner or other applications with access to
   the resource owner's user-agent.

   Implicit grants improve the responsiveness and efficiency of some
   clients (such as a client implemented as an in-browser application),
   since it reduces the number of round trips required to obtain an
   access token.  However, this convenience should be weighed against
   the security implications of using implicit grants, such as those
   described in Sections 10.3 and 10.16, especially when the
   authorization code grant type is available.

1.3.3.  Resource Owner Password Credentials

   The resource owner password credentials (i.e., username and password)
   can be used directly as an authorization grant to obtain an access
   token.  The credentials should only be used when there is a high
   degree of trust between the resource owner and the client (e.g., the
   client is part of the device operating system or a highly privileged
   application), and when other authorization grant types are not
   available (such as an authorization code).

   Even though this grant type requires direct client access to the
   resource owner credentials, the resource owner credentials are used
   for a single request and are exchanged for an access token.  This
   grant type can eliminate the need for the client to store the
   resource owner credentials for future use, by exchanging the
   credentials with a long-lived access token or refresh token.

1.3.4.  Client Credentials

   The client credentials (or other forms of client authentication) can
   be used as an authorization grant when the authorization scope is
   limited to the protected resources under the control of the client,
   or to protected resources previously arranged with the authorization
   server.  Client credentials are used as an authorization grant
   typically when the client is acting on its own behalf (the client is
   also the resource owner) or is requesting access to protected
   resources based on an authorization previously arranged with the
   authorization server.

1.4.  Access Token

   Access tokens are credentials used to access protected resources.  An
   access token is a string representing an authorization issued to the
   client.  The string is usually opaque to the client.  Tokens
   represent specific scopes and durations of access, granted by the
   resource owner, and enforced by the resource server and authorization
   server.

   The token may denote an identifier used to retrieve the authorization
   information or may self-contain the authorization information in a
   verifiable manner (i.e., a token string consisting of some data and a
   signature).  Additional authentication credentials, which are beyond
   the scope of this specification, may be required in order for the
   client to use a token.

   The access token provides an abstraction layer, replacing different
   authorization constructs (e.g., username and password) with a single
   token understood by the resource server.  This abstraction enables
   issuing access tokens more restrictive than the authorization grant
   used to obtain them, as well as removing the resource server's need
   to understand a wide range of authentication methods.

   Access tokens can have different formats, structures, and methods of
   utilization (e.g., cryptographic properties) based on the resource
   server security requirements.  Access token attributes and the
   methods used to access protected resources are beyond the scope of
   this specification and are defined by companion specifications such
   as [RFC6750].

1.5.  Refresh Token

   Refresh tokens are credentials used to obtain access tokens.  Refresh
   tokens are issued to the client by the authorization server and are
   used to obtain a new access token when the current access token
   becomes invalid or expires, or to obtain additional access tokens
   with identical or narrower scope (access tokens may have a shorter
   lifetime and fewer permissions than authorized by the resource
   owner).  Issuing a refresh token is optional at the discretion of the
   authorization server.  If the authorization server issues a refresh
   token, it is included when issuing an access token (i.e., step (D) in
   Figure 1).

   A refresh token is a string representing the authorization granted to
   the client by the resource owner.  The string is usually opaque to
   the client.  The token denotes an identifier used to retrieve the authorization information.  Unlike access tokens, refresh tokens are
   intended for use only with authorization servers and are never sent
   to resource servers.