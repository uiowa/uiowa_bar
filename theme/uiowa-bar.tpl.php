<?php
/**
 * @file uiowa-bar.tpl.php
 *
 * This template handles the layout of the Uiowa Branding Bar.
 *
 * Variables available:
 * 
 *
 */
?>

<div id="ui-wrapper"><div class="container">
  <div id="ui-global-bar">
    <div id="ui-logo"><a href="http://www.uiowa.edu">The University of Iowa</a></div>
    <div id="ui-global-bar-nav">
      <div id="ui-global-links">
        <ul>
          <li><a href="http://www.uiowa.edu/homepage/directories/" class="icon phonebook" title="Phonebook">Phonebook</a></li>
          <li><a href="http://www.uiowa.edu/homepage/hub/tours.html" class="icon maps" title="Maps">Maps</a></li>
          <li><a href="http://www.uiowa.edu/homepage/search/index.html" class="icon a-z" title="A-Z">A-Z</a></li>
          <li><a href="#" class="icon search" title="Search">Search</a></li>
        </ul>
      </div><!-- /ui-global-links -->
      <div id="gsa-search">
        <form action="http://search.uiowa.edu/search" method="get">
          <fieldset>
            <legend class="element-hidden">Search</legend>
            <div id="search-box">
              <label class="element-hidden" for="search-terms">Search Terms</label> 
              <input id="search-terms" maxlength="256" name="q" placeholder="Start Searching ..." size="15" type="text" value="" /> 
              
              <label for="sitesearch" id="site-search-label">for</label><div id="sitesearch-container">
              <select id="sitesearch" name="sitesearch">
                <option id="search-this-site" value="' . $_SERVER['SERVER_NAME'] . '">This Site</option>
                <option id="search-ui" value="www.uiowa.edu">All Sites</option>
              </select>

              <input id="submit-search" name="btnG" type="submit" value="Search" />
              <input name="site" type="hidden" value="default_collection" />
              <input name="client" type="hidden" value="default_frontend" />
              <input name="output" type="hidden" value="xml_no_dtd" />
              <input name="proxystylesheet" type="hidden" value="default_frontend" />
            </div><!-- /search-box -->
          </fieldset>
        </form>
      </div><!-- /gsa-search -->
    </div><!-- /global-bar-nav -->
  </div><!-- /ui-global-bar -->
  </div></div><!-- /ui-wrapper and conatiner -->
